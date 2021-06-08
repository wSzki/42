
make re


echo "=============="
echo "100"
ARG=$(ruby -e "puts (0...100).to_a.shuffle.join(' ')") && ./push_swap $ARG | ./checker_linux $ARG
ARG=$(ruby -e "puts (0...100).to_a.shuffle.join(' ')") && ./push_swap $ARG | wc -l
echo "=============="
echo "101"
ARG=$(ruby -e "puts (0...101).to_a.shuffle.join(' ')") && ./push_swap $ARG | ./checker_linux $ARG
ARG=$(ruby -e "puts (0...101).to_a.shuffle.join(' ')") && ./push_swap $ARG | wc -l
echo "=============="
echo "102"
ARG=$(ruby -e "puts (0...102).to_a.shuffle.join(' ')") && ./push_swap $ARG | ./checker_linux $ARG
ARG=$(ruby -e "puts (0...102).to_a.shuffle.join(' ')") && ./push_swap $ARG | wc -l
echo "=============="
echo "103"
ARG=$(ruby -e "puts (0...103).to_a.shuffle.join(' ')") && ./push_swap $ARG | ./checker_linux $ARG
ARG=$(ruby -e "puts (0...103).to_a.shuffle.join(' ')") && ./push_swap $ARG | wc -l
echo "=============="
echo "104"
ARG=$(ruby -e "puts (0...104).to_a.shuffle.join(' ')") && ./push_swap $ARG | ./checker_linux $ARG
ARG=$(ruby -e "puts (0...104).to_a.shuffle.join(' ')") && ./push_swap $ARG | wc -l





echo "=============="
echo "500"
ARG=$(ruby -e "puts (0...500).to_a.shuffle.join(' ')") && ./push_swap $ARG | ./checker_linux $ARG
ARG=$(ruby -e "puts (0...500).to_a.shuffle.join(' ')") && ./push_swap $ARG | wc -l
echo "=============="
echo "501"
ARG=$(ruby -e "puts (0...501).to_a.shuffle.join(' ')") && ./push_swap $ARG | ./checker_linux $ARG
ARG=$(ruby -e "puts (0...501).to_a.shuffle.join(' ')") && ./push_swap $ARG | wc -l
echo "=============="
echo "502"
ARG=$(ruby -e "puts (0...502).to_a.shuffle.join(' ')") && ./push_swap $ARG | ./checker_linux $ARG
ARG=$(ruby -e "puts (0...502).to_a.shuffle.join(' ')") && ./push_swap $ARG | wc -l
echo "=============="
echo "503"
ARG=$(ruby -e "puts (0...503).to_a.shuffle.join(' ')") && ./push_swap $ARG | ./checker_linux $ARG
ARG=$(ruby -e "puts (0...503).to_a.shuffle.join(' ')") && ./push_swap $ARG | wc -l
echo "=============="
