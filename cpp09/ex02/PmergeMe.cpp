#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	_vec = other._vec;
	_deque = other._deque;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deque = other._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::fillVector(int count, char **numbers)
{
	for (int i = 1; i < count; i++)
	{
		std::stringstream ss(numbers[i]);
		int n;
		std::string leftover;
		if (!(ss >> n) || n < 0 || (ss >> leftover))
		{
			std::cerr << "Error" << std::endl;
			exit(1);
		}
		_vec.push_back(n);
	}
}

void PmergeMe::sortVector()
{	
	if (_vec.empty())
		return;
	if (_vec.size() == 1)
	{
		_vecIdx.push_back(0);
		return;
	}
	if (_vec.size() == 2)
	{
		if (_vec[0] <= _vec[1])
		{
			_vecIdx.push_back(0);
			_vecIdx.push_back(1);
		}
		else
		{
			_vecIdx.push_back(1);
			_vecIdx.push_back(0);
		}
		return;
	}

	int lastIdx = -1;
	if (_vec.size() % 2 != 0)
		lastIdx = _vec.size() - 1;

	fillIdxPairsVector();
	buildMainChainVector();
	insertPendingVector();

	if (lastIdx != -1)
	{
		std::vector<int>::iterator pos =
			lowerBoundByValue(_vecIdx.begin(), _vecIdx.end(), _vec[lastIdx]);
		_vecIdx.insert(pos, lastIdx);
	}
}

void PmergeMe::fillIdxPairsVector()
{
	for (size_t i = 0; i + 1 < _vec.size(); i += 2)
	{
		if (_vec[i] > _vec[i + 1])
			_idxPairs.push_back(std::make_pair(i, i + 1));
		else
			_idxPairs.push_back(std::make_pair(i + 1, i));
	}
}

// void PmergeMe::buildMainChainVector()
// {
//     if (_idxPairs.empty())
//         return ;

//     for (size_t i = 0; i < _idxPairs.size(); i++)
//         for (size_t j = i + 1; j < _idxPairs.size(); j++)
//             if (_vec[_idxPairs[i].first] > _vec[_idxPairs[j].first])
//                 std::swap(_idxPairs[i], _idxPairs[j]);

//     _vecIdx.clear();
//     for (size_t i = 0; i < _idxPairs.size(); i++)
//         _vecIdx.push_back(_idxPairs[i].first);
// }

void PmergeMe::buildMainChainVector()
{
	if (_idxPairs.empty())
		return ;

	std::vector<int> winners;
	for (size_t i = 0; i < _idxPairs.size(); i++)
		winners.push_back(_vec[_idxPairs[i].first]);

	PmergeMe sub;
	sub.setVector(winners);
	sub.sortVector();
	std::vector<int> order = sub.getSorted();

	// reorder pairs directly by that permutation
	std::vector<std::pair<int, int> > sortedPairs;
	for (size_t i = 0; i < order.size(); i++)
		sortedPairs.push_back(_idxPairs[order[i]]);
	_idxPairs = sortedPairs;

	_vecIdx.clear();
	for (size_t i = 0; i < _idxPairs.size(); i++)
		_vecIdx.push_back(_idxPairs[i].first);
}

void PmergeMe::insertPendingVector()
{
	std::vector<int> jacobsthal = buildJacobsthalVector();
	_vecIdx.insert(_vecIdx.begin(), _idxPairs[0].second);

	int prev = 1;
	for (size_t j = 1; j < jacobsthal.size(); j++)
	{
		for (int k = jacobsthal[j] - 1; k >= prev; k--)
		{
			std::vector<int>::iterator bound =
				lowerBoundByValue(_vecIdx.begin(), _vecIdx.end(), _vec[_idxPairs[k].first]);
			std::vector<int>::iterator pos =
				lowerBoundByValue(_vecIdx.begin(), bound, _vec[_idxPairs[k].second]);
			_vecIdx.insert(pos, _idxPairs[k].second);
		}
		prev = jacobsthal[j];
	}
}

std::vector<int> PmergeMe::buildJacobsthalVector()
{
	std::vector<int> jacobsthal;
	jacobsthal.push_back(1);
	if (_idxPairs.size() < 3)
	{
		if (_idxPairs.size() > 1)
			jacobsthal.push_back(_idxPairs.size());
		return jacobsthal;
	}
	jacobsthal.push_back(3);
	while (true)
	{
		int next = jacobsthal[jacobsthal.size()-1] + 2 * jacobsthal[jacobsthal.size()-2];
		if (next >= (int)_idxPairs.size())
		{
			jacobsthal.push_back(_idxPairs.size());
			break;
		}
		jacobsthal.push_back(next);
	}
	return jacobsthal;
}

std::vector<int>::iterator PmergeMe::lowerBoundByValue(
	std::vector<int>::iterator lo, std::vector<int>::iterator hi, int val)
{
	while (lo < hi)
	{
		std::vector<int>::iterator mid = lo + (hi - lo) / 2;
		if (_vec[*mid] < val)
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
}

void PmergeMe::printVector() const
{
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::printSortedVector() const
{
	for (size_t i = 0; i < _vecIdx.size(); i++)
		std::cout << _vec[_vecIdx[i]] << " ";
	std::cout << std::endl;
}