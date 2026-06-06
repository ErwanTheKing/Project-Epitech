##############################################
# TEST 1 — Translation simple
##############################################
echo "\033[41m++++++++++++++++++++++++++++++++++++++++++++++\033[0m"
echo ""
echo "\033[1m\033[4m\033[34mTEST 1 : TRANSLATION\033[0m"
./102architect 5 0 -t -1 1
echo ""
echo "return value : $?"
echo ""
echo "\033[1m\033[4m\033[34mEXPECTED\033[0m"
echo "Translation along vector (-1, 1)
1.00	0.00	-1.00
0.00	1.00	1.00
0.00	0.00	1.00
(5.00, 0.00) => (4.00, 1.00)"
echo ""
echo "return value : 0"
echo ""
echo "\033[41m++++++++++++++++++++++++++++++++++++++++++++++\033[0m"



##############################################
# TEST 2 — Scaling simple
##############################################
echo ""
echo "\033[1m\033[4m\033[34mTEST 2 : SCALING\033[0m"
./102architect 2 3 -z 2 4
echo ""
echo "return value : $?"
echo ""
echo "\033[1m\033[4m\033[34mEXPECTED\033[0m"
echo "Scaling by factors 2 and 4
2.00	0.00	0.00
0.00	4.00	0.00
0.00	0.00	1.00
(2.00, 3.00) => (4.00, 12.00)"
echo ""
echo "return value : 0"
echo ""
echo "\033[41m++++++++++++++++++++++++++++++++++++++++++++++\033[0m"



##############################################
# TEST 3 — Rotation simple
##############################################
echo ""
echo "\033[1m\033[4m\033[34mTEST 3 : ROTATION\033[0m"
./102architect 1 0 -r 90
echo ""
echo "return value : $?"
echo ""
echo "\033[1m\033[4m\033[34mEXPECTED\033[0m"
echo "Rotation by a 90 degree angle
0.00	-1.00	0.00
1.00	0.00	0.00
0.00	0.00	1.00
(1.00, 0.00) => (0.00, 1.00)"
echo ""
echo "return value : 0"
echo ""
echo "\033[41m++++++++++++++++++++++++++++++++++++++++++++++\033[0m"



##############################################
# TEST 4 — Reflection simple
##############################################
echo ""
echo "\033[1m\033[4m\033[34mTEST 4 : REFLECTION\033[0m"
./102architect 2 1 -s 45
echo ""
echo "return value : $?"
echo ""
echo "\033[1m\033[4m\033[34mEXPECTED\033[0m"
echo "Reflection over an axis with an inclination angle of 45 degrees
0.00	1.00	0.00
1.00	0.00	0.00
0.00	0.00	1.00
(2.00, 1.00) => (1.00, 2.00)"
echo ""
echo "return value : 0"
echo ""
echo "\033[41m++++++++++++++++++++++++++++++++++++++++++++++\033[0m"



##############################################
# TEST 5 — Combinaison : translation + scaling
##############################################
echo ""
echo "\033[1m\033[4m\033[34mTEST 5 : COMBO T + Z\033[0m"
./102architect 1 1 -t 2 3 -z 2 2
echo ""
echo "return value : $?"
echo ""
echo "\033[1m\033[4m\033[34mEXPECTED\033[0m"
echo "Translation along vector (2, 3)
Scaling by factors 2 and 2
2.00	0.00	4.00
0.00	2.00	6.00
0.00	0.00	1.00
(1.00, 1.00) => (6.00, 8.00)"
echo ""
echo "return value : 0"
echo ""
echo "\033[41m++++++++++++++++++++++++++++++++++++++++++++++\033[0m"



##############################################
# TEST 6 — Combo T + R + S
##############################################
echo ""
echo "\033[1m\033[4m\033[34mTEST 6 : COMBO T + R + S\033[0m"
./102architect 1 2 -t 3 -1 -r 180 -s 0
echo ""
echo "return value : $?"
echo ""
echo "\033[1m\033[4m\033[34mEXPECTED\033[0m"
echo "Translation along vector (3, -1)
Rotation by a 180 degree angle
Reflection over an axis with an inclination angle of 0 degrees
-1.00	0.00	-3.00
0.00	1.00	1.00
0.00	0.00	1.00
(1.00, 2.00) => (-2.00, 1.00)"
echo ""
echo "return value : 0"
echo ""
echo "\033[41m++++++++++++++++++++++++++++++++++++++++++++++\033[0m"



##############################################
# TEST 7 — Option -h
##############################################
echo ""
echo "\033[1m\033[4m\033[34mTEST 7 : HELP\033[0m"
./102architect -h
echo ""
echo "return value : $?"
echo ""
echo "\033[1m\033[4m\033[34mEXPECTED\033[0m"
echo "USAGE
    ./102architect x y transfo1 arg11 [arg12] [transfo2 arg21 [arg22]] ...

DESCRIPTION
    x   abscissa of the original point
    y   ordinate of the original point
    transfo arg1 [arg2]
    -t i j  translation along vector (i, j)
    -z m n  scaling by factors m (x-axis) and n (y-axis)
    -r d    rotation centered in O by a d degree angle
    -s d    reflection over the axis passing through O with an inclination
            angle of d degrees"
echo ""
echo "return value : 0"
echo ""
echo "\033[41m++++++++++++++++++++++++++++++++++++++++++++++\033[0m"



##############################################
# TEST 8 — Erreur : pas assez d’arguments
##############################################
echo ""
echo "\033[1m\033[4m\033[34mTEST 8 : ERROR (too few args)\033[0m"
./102architect 1 2 -t
echo ""
echo "return value : 84"
echo ""
echo "\033[1m\033[4m\033[34mEXPECTED\033[0m"
echo "return value : 84"
echo ""
echo "\033[41m++++++++++++++++++++++++++++++++++++++++++++++\033[0m"



##############################################
# TEST 9 — Erreur : argument non numérique
##############################################
echo ""
echo "\033[1m\033[4m\033[34mTEST 9 : ERROR (invalid number)\033[0m"
./102architect a 3 -t 1 2
echo ""
echo "return value : 84"
echo ""
echo "\033[1m\033[4m\033[34mEXPECTED\033[0m"
echo "return value : 84"
echo ""
echo "\033[41m++++++++++++++++++++++++++++++++++++++++++++++\033[0m"
