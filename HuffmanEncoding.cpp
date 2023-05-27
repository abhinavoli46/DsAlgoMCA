#include<bits/stdc++.h>
using namespace std; 
//Structure of Node
struct Node
{
    int frequency;
    char character;
    Node* left;
    Node* right;
};

/*
    Function taking character and its frequency and returning its pointer
    Child Node are initialized as null
*/ 
Node* makeNode(char character,int frequency,Node* left,Node* right)
{
    Node* node = new Node();
    node->character = character;
    node->frequency = frequency;
    node->left = left;
    node->right = right;
    return node;
}
/*  
    In case of priority queue it takes structure as comparator where we 
    have to overload () operator to achieve functionality.
*/
struct comparatorFunction
{
    bool operator ()(Node* left,Node* right)
    {
        return (left->frequency) > (right->frequency);
    }
};


//Encode each character by appending 0 to left and 1 to right subtree
void encode(Node* root,string code,unordered_map<char,string>& characterCodeMap)
{
    if(root == nullptr)
        return;
    if(root->left == nullptr && root->right == nullptr)
    {
        characterCodeMap[root->character] = code;
    }

    encode(root->left,code + "0",characterCodeMap);
    encode(root->right,code + "1",characterCodeMap);
}

//Function to print the coded string
void makeEncodedString(string inputSting,string& outputstring,unordered_map<char,string>& characterCodeMap)
{
    for(auto character : inputSting)
    {
        outputstring += characterCodeMap[character];
    }
}
//Building huffman Tree
void buildHuffmanTree(string inputString)
{
    unordered_map<char,int> um;
    for(auto character : inputString)
    {
        um[character]++;
    }
    //Make min heap of Node structure on the basis of count of characters
    priority_queue<Node*,vector<Node*>,comparatorFunction> pq;
    for(auto charCount : um)
        pq.push(makeNode(charCount.first,charCount.second,nullptr,nullptr));

    while(pq.size() != 1)
    {
        Node* leftChild = pq.top();
        pq.pop();
        Node* rightChild = pq.top();
        pq.pop();

        int sumOfFrequency = leftChild->frequency + rightChild->frequency;
        pq.push(makeNode('\0',sumOfFrequency,leftChild,rightChild));
    }

    Node* root = pq.top();

    //Use encode() to encode according to tree made
    unordered_map<char,string> characterCodesMap;
    encode(root,"",characterCodesMap);
    //Convert input string to code using characterCodesMap
    string outputString ="";
    makeEncodedString(inputString,outputString,characterCodesMap);
    cout << "\nAfter Encoding :\n" << outputString; 


    cout << "\n\nFor this input Huffman Codes Generated are : ";
    cout << "\nCharacter\tCode"<<endl;
    for(auto it : characterCodesMap)
    {
        cout << it.first << "\t\t" << it.second << endl;
    }
}

int main()
{   
    cout << "\nEnter a string : ";
    string str;
    getline(cin,str);
    cout << "\nYou entered : " << str;
    buildHuffmanTree(str);
    return 0;
}

/*
Flow Of Code -> 
1. Create a structure Node with character, frequency left and right child
2. Create a unordered map to store character and its frequency.
3. Create a priority queue and iterate through map to push elements based on their frequencies (push element made by createNode() function).
    -> It will be a min heap where the type will be of Node* and we need a comparator to make heap according to frequency as ordering parameter
    -> for priority queue we have to make a comparator of type struct and overload () operator.
4. Extract 2 minimum element from heap and add their frequency.
    -> Create a new Node and make first minimum its left child and second minimum its right child and frequency as the sum calculated and character as null character'\0'.
    -> Push it into the queue.
    -> Run this loop until 1 node remains in the queue i.e root node.
5. For encoding we use recursion.
    Create an unordered map of character and string, take an empty string and root node pointer.
    Pass all to encode function where (pass empty map as reference)
    if root is null return. 
    if we found a child node we add <characterOfChildNode,valueOfStringInCurrentCall> into the map passed.
    Call for left child by adding a 0 to string
    Call for right child by adding a 1 to string
6. The map now conatins character with their code.
7. Traverse the input string and fetch the code from map character by character.
*/