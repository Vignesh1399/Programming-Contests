struct trie{
        struct trie* node[2];
        trie(){
            for(int i=0;i<2;i++)
                node[i] = NULL;
        }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        struct trie* root = new trie();
        int ans = 0;
        for(int i=0;i<(int)nums.size();i++){
            struct trie* temp = root;
            for(int j=31;j>=0;j--){
                if((nums[i]>>j)&1){
                    if(temp->node[1] == NULL)
                        temp->node[1] = new trie();
                    temp = temp->node[1];
                }
                else{
                    if(temp->node[0] == NULL)
                        temp->node[0] = new trie();
                    temp = temp->node[0];
                }
            }
        }
        for(int i=0;i<(int)nums.size();i++){
            int cur = 0;
            struct trie* temp = root;
            for(int j=31;j>=0;j--){
                if((nums[i]>>j)&1){
                    if(temp->node[0] != NULL){
                        cur += (1<<j);
                        temp = temp->node[0];
                    }
                    else
                        temp = temp->node[1];
                }
                else{
                    if(temp->node[1] != NULL){
                        cur += (1<<j);
                        temp = temp->node[1];
                    }
                    else
                        temp = temp->node[0];
                }
            }
            ans = max(ans,cur);
        }
        return ans;
    }
};