**Bruteforce-**
we can check for valid row then valid col and then valid boxes if all true then we return true else false.
**Optimized-**
we can use the cocept of Hashset, it says that a hashset can not store duplicate inside it.
so if we try to fill duplicate in it, it return false, using this we can solve it in single iteration.
we will go to all filled cells and we will save its row,coland box in hashset in for of strings. if at any cell a string repeat itself then we return false.
formula to calculate box no. for a number at cell [i] [j] = (i/3)*3+j/3
`
class Solution {
public:
bool isValidSudoku(vector<vector<char>>& board) {
//since we have to verify that each element is appears once or not... for that purpose here we use
//vector of sets since set stores only unique entries
vector<set<int>> rows(9),cols(9),blocks(9);
for(int i=0;i<9;i++){
for(int j=0;j<9;j++){
//if board[i][j] entry is '.' then we just continue as we only care about the duplicate values
if(board[i][j] == '.') continue;
int curr = board[i][j]; //we can get the value at given index to check that if it is already present in set or not
//here our count function returns 1 if value is already present in row or column or block otherwise it will return 0
//for block look for notes...
if(rows[i].count(curr) || cols[j].count(curr) ||
blocks[(i/3)*3 + j/3].count(curr)){
return false; //we return false because the value currently we have is already present in set
}
//if we don't found the value then after that we must enter this value in our set
rows[i].insert(curr);
cols[j].insert(curr);
blocks[(i/3*3) + j/3].insert(curr);
}
}
//after loop finishes our control reaches here that means our sudoko is valid...
return true;
}
};
`