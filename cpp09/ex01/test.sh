#!/bin/bash

pass=0
fail=0

check() {
    local desc="$1"
    local expected="$2"
    local actual="$3"
    if [ "$actual" = "$expected" ]; then
        echo "PASS: $desc"
        pass=$((pass + 1))
    else
        echo "FAIL: $desc"
        echo "  expected: $expected"
        echo "  got:      $actual"
        fail=$((fail + 1))
    fi
}

check "simple add"         "3"     "$(./RPN '1 2 +')"
check "complex expression" "14"    "$(./RPN '5 1 2 + 4 * + 3 -')"
check "subject example 1"  "42"    "$(./RPN '7 7 * 7 -')"
check "subject example 2"  "42"    "$(./RPN '8 9 * 9 - 9 - 9 - 4 - 1 +')"
check "subject example 3"  "0"     "$(./RPN '1 2 * 2 / 2 * 2 4 - +')"
check "zeros"              "0"     "$(./RPN '0 0 +')"
check "max digit mul"      "81"    "$(./RPN '9 9 *')"
check "division by zero"   "Error: division by zero." "$(./RPN '1 0 /' 2>&1)"
check "no operands"        "Error" "$(./RPN '+' 2>&1)"
check "one operand"        "Error" "$(./RPN '1 +' 2>&1)"
check "no operator"        "Error" "$(./RPN '1 2' 2>&1)"
check "empty input"        "Error" "$(./RPN '' 2>&1)"
check "brackets"           "Error" "$(./RPN '(1 + 1)' 2>&1)"
check "leftover number"    "Error" "$(./RPN '1 2 + 3' 2>&1)"
check "invalid token"      "Error" "$(./RPN 'abc' 2>&1)"
check "number >= 10"       "Error" "$(./RPN '10 2 +' 2>&1)"
check "float input"        "Error" "$(./RPN '1.5 2 +' 2>&1)"
echo ""
echo "Results: $pass passed, $fail failed"