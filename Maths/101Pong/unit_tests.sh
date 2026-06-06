echo "\033[41m++++++++++++++++++++++++++++++++++++++++++++++\033[0m"
echo ""
echo "\033[1m\033[4m\033[34mMY_101PONG\033[0m"
./101pong 1.1 3 5 -7 9 -2 4
echo ""
echo "return value  : $?"
echo ""
echo "\033[1m\033[4m\033[34mEXCEPTED\033[0m"
echo "The velocity vector of the ball is:
(-8.10, 6.00, -3.00)
At time t + 4, ball coordinates will be:
(-39.40, 33.00, -10.00)
The incidence angle is:
16.57 degrees"
echo ""
echo "return value : 0"
echo ""
echo "\033[41m++++++++++++++++++++++++++++++++++++++++++++++\033[0m"
echo ""
echo "\033[1m\033[4m\033[34mMY_101PONG (no hit)\033[0m"
./101pong 0 0 5 1 1 6 3
echo ""
echo "return value  : $?"
echo ""
echo "\033[1m\033[4m\033[34mEXCEPTED\033[0m"
echo "The velocity vector of the ball is:
(1.00, 1.00, 1.00)
At time t + 3, ball coordinates will be:
(4.00, 4.00, 9.00)
The ball won't reach the paddle."
echo ""
echo "return value : 0"
echo ""
echo "\033[41m++++++++++++++++++++++++++++++++++++++++++++++\033[0m"
echo ""
echo "\033[1m\033[4m\033[34mMY_101PONG (invalid arg)\033[0m"
./101pong 0 a 1 2 3 4 5
echo ""
echo "return value  : 84"
echo ""
echo "\033[1m\033[4m\033[34mEXCEPTED\033[0m"
echo "return value : 84"
echo ""
echo "\033[41m++++++++++++++++++++++++++++++++++++++++++++++\033[0m"
echo ""
echo "\033[1m\033[4m\033[34mMY_101PONG (negative n)\033[0m"
./101pong 1 2 3 4 5 6 -2
echo ""
echo "return value  : 84"
echo ""
echo "\033[1m\033[4m\033[34mEXCEPTED\033[0m"
echo "n can't be negative"
echo "return value : 84"
echo ""
echo "\033[41m++++++++++++++++++++++++++++++++++++++++++++++\033[0m"
echo ""
echo "\033[1m\033[4m\033[34mMY_101PONG (-h)\033[0m"
./101pong -h
echo ""
echo "return value  : $?"
echo ""
echo "\033[1m\033[4m\033[34mEXCEPTED\033[0m"
echo "USAGE
    ./101pong x0 y0 z0 x1 y1 z1 n

DESCRIPTION
    x0 ball abscissa at time t - 1
    y0 ball ordinate at time t - 1
    z0 ball altitude at time t - 1
    x1 ball abscissa at time t
    y1 ball ordinate at time t
    z1 ball altitude at time t
    n time shift (greater than or equal to zero, integer)"
echo ""
echo "return value : 0"
echo ""
echo "\033[41m++++++++++++++++++++++++++++++++++++++++++++++\033[0m"
