#include<bits/stdc++.h>
using namespace std;

string alienOrder(vector<string>& words) {
map<char, vector<char>> adjacencyList;
        
        // number of edges connecting to key char
        map<char, int> edgeCounts;
        
        // init lists
        for( string& word : words )
        {
            for( char letter : word )
            {
                // no need to actuall set them to anything, just access them to esure they exist
                // and will be inited to empty / 0
                adjacencyList[letter];
                edgeCounts[letter];
            }
        }
        
        int wordCount = words.size();
        
        for( int i = 0; i < wordCount - 1; ++i )
        {
            string& lWord = words[i];
            string& rWord = words[i+1];
            
            int lSize = lWord.length();
            int rSize = rWord.length();
            
            int length = max(lSize, rSize);
            
            int j = 0;
            for( ; j < length; ++j )
            {                
                if( lWord[min(j, lSize-1)] != rWord[min(j, rSize-1)] )
                {
                    break;
                }
            }
            
            // no difference found, ingore it
            if( j >= lSize && j >= rSize )
            {
                continue;
            }
            else if( j >= rSize )
            {
                // right word is a prefix of left word
                // invalid list
                return "";
            }
            
            
            adjacencyList[lWord[min(j, lSize-1)]].push_back( rWord[min(j, rSize-1)] );
            edgeCounts[rWord[min(j, rSize-1)]]++;
        }
        
        string result;
        queue<char> letterQueue;
        for( auto i : edgeCounts )
        {
            if( i.second == 0 )
            {
                letterQueue.push( i.first );
            }
        }
        
        while( !letterQueue.empty() )
        {
            char letter = letterQueue.front();
            letterQueue.pop();
            
            result += letter;
            
            vector<char>& edges = adjacencyList[letter];
            for( char edge : edges )
            {
                if( edgeCounts[edge] > 0 && --edgeCounts[edge] == 0 )
                {
                    letterQueue.push( edge );
                }
            }
        }
        
        int remaining = 0;
        for( auto i : edgeCounts )
        {
            remaining += i.second;
        }
        
        if( remaining > 0 )
        {
            return "";
        }
        
        return result;
}