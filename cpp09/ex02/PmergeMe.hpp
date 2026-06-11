#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <iostream>
# include <sstream>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void	fillVector(int count, char **numbers);
		void	sortVector();

		void	printVector() const;
		void	printSortedVector() const;

		void	fillDeque(int argc, char **argv);
		void	sortDeque();
		void	printDeque() const;

	private:
		std::vector<int>					_vec;
		std::vector<int>					_vecIdx;
		std::vector<std::pair<int, int> >	_idxPairs;

		std::deque<int>						_deque;
		std::deque<std::pair<int, int> >	_dequePairs;


		void 	fillIdxPairsVector();
		void 	buildMainChainVector();
		void	insertPendingVector();
		std::vector<int>::iterator lowerBoundByValue(
			std::vector<int>::iterator lo, std::vector<int>::iterator hi, int val);

		std::vector<int> buildJacobsthalVector();
		std::vector<int> buildJacobsthalVectorD();

		
		void 	fillPairsDeque();
		void 	buildMainChainDeque();
		void	insertPendingDeque();


		void setVector(const std::vector<int> &v) { _vec = v; }
		const std::vector<int> &getSorted() const { return _vecIdx; }
};

#endif