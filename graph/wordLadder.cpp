// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        set<string> s;
        for(auto it: wordList)
            s.insert(it);
        if(s.find(targetWord) == s.end())
            return 0;
        queue<string> q;
        int dis=0;
        q.push(startWord);
        while(!q.empty()){
            dis++;
            int l = q.size();
           
            for(int i=0;i<l;i++)
            {
                
                
                string w = q.front();
                q.pop();
                
                for(int j=0;j<w.length();j++){
                    for(int i=0;i<26;i++)
                    {
                        char c = 'a' + i;
                        string t = w;
                        
                        t[j] = c;
                        // cout<<t<<endl;
                        if(t == targetWord)
                            return dis+1;
                        if(s.find(t) != s.end()){
                            q.push(t);
                            s.erase(s.find(t));
                        }
                            
                        
                    }
                }
            }
        }
        
        return 0;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends