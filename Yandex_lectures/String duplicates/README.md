<img src="Yandex_lectures/Readme_info/1610504427_4-p-belii-fon-dlya-yandeksa-13.jpg" alt="drawing" width="100"/>

# String duplicates

The **task** is to find the letter in string wich **have the most duplicates**.

* The [first](https://github.com/EjenY-Poltavchiny/CPLUS-practice/blob/main/String%20duplicates/solution_1.cpp) solution uses primitive string traversal using **nested loops**. Asymptotic complexity is $O(N^2)$. Where **N** is amount of letters in string.

* The [second](https://github.com/EjenY-Poltavchiny/CPLUS-practice/blob/main/String%20duplicates/solution_2.cpp) solution uses **set** structure. Asymptotic complexity is $O(N \cdot K)$. Where **K** is amount of different letters (may be equal to **N**).

* The [third](https://github.com/EjenY-Poltavchiny/CPLUS-practice/blob/main/String%20duplicates/solution_3.cpp) solution uses **map** structure. Asymptotic complexity is $O(N + K) = O(N)$.
