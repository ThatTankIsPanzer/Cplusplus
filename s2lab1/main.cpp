#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

//int counter = 0;
struct NODE {
    int data;
    NODE *link;
};

void insertLinkedList(NODE *&head, int data);
bool searchLinkedList(NODE *head, int target, NODE *&prePtr, NODE *&curPtr);
void deleteLinkedList(NODE *&listHead, int data);

void  createList(ifstream &inFile, NODE *&head)
{
    int DATA;
    vector<int> vecData;
    while(inFile >> DATA)
    {
        vecData.push_back(DATA);
        for(int i = 0; i < vecData.size(); i++)
        {
            for(int j = 0; j < vecData.size(); j++)
            {
                if(i != j)
                {
                    if(vecData[i] == vecData[j])
                    {
                        vecData.pop_back();
                    }
                }
            }
        }
    }
    sort(vecData.begin(), vecData.end(), greater <int>());
    for(int i = vecData.size()-1; i >= 0; i--)
    {
        insertLinkedList(head, vecData[i]);
    }

}

void deleteElements(ifstream &inFileDel, NODE *&head)
{
    int DATA;
    vector<int> vecData;
    while(inFileDel >> DATA)
    {
        vecData.push_back(DATA);
        for(int i = 0; i < vecData.size(); i++)
        {
            for(int j = 0; j < vecData.size(); j++)
            {
                if(i != j)
                {
                    if(vecData[i] == vecData[j])
                    {
                        vecData.pop_back();
                    }
                }
            }
        }
    }
    sort(vecData.begin(), vecData.end(), greater <int>());
    for(int i = 0; i < vecData.size(); i++)
    {
        deleteLinkedList(head, vecData[i]);
    }
}

bool searchLinkedList(NODE *head, int target, NODE *&prePtr, NODE *&curPtr)
{
    prePtr = NULL;
    curPtr = head;
    while (target < curPtr->data)
    {
        prePtr = curPtr;
        curPtr = curPtr->link;
    }
    if (curPtr->data == target)
    {
        //cout<< curPtr->data <<" ";
        return true;

    }
    else
    {
        return false;
    }
}

void insertLinkedList(NODE *&head, int data)
{
    NODE *aNode; // aNode is a pointer to a node
    aNode = new NODE; // create a node pointed by aNode
    aNode->data = data; // store data into the node
    aNode->link = head; // set the link of the node to NULL
    head = aNode;
}

void deleteLinkedList(NODE *&listHead, int data)
{
    NODE *cur;
    NODE *pre;
    if(!searchLinkedList(listHead, data, pre, cur))
        return ;
    if(pre == NULL)
    {
        listHead = cur->link;
    }
    else
    {
        pre->link = cur->link;
        cur->link = NULL;
        //cout <<"deleteLinkedList "<< cur->data << endl;
        delete cur;

    }
}

void displayList(NODE *head){
    int count = 0; // Used for counting the number of nodes
    NODE *tempPtr = head; // Set tempPtr to the head of the linked-list
    while(tempPtr != NULL) // Check whether get to the end of the linked-list
    {
        cout << tempPtr -> data << " "; // Print out the data stored in the node
        tempPtr = tempPtr -> link; // Move to the next node
        count++;
        if(count % 15 == 0) // Change line if already printing 15 numbers
            cout << endl;
    }
    cout << endl;
    cout << "Total number of elements in the linked list: " << count << endl;

}

int main() {
    string dataFilename;
    ifstream inFile;
    string delDataFilename;
    ifstream inFileDel;

// First part

    cout << "File name for creating linked list: ";
    cin >> dataFilename;
    cout << endl;
    inFile.open(dataFilename);
    NODE *listHead = NULL;
    if(!inFile){
        cout << "File open error!" << endl;
        exit(1);
    }
    createList(inFile, listHead);
    inFile.close();
    displayList(listHead);

// Second part

    cout << "\nFile name for linked list deletion: ";
    cin >> delDataFilename;
    inFileDel.open(delDataFilename);
    if(!inFileDel){
        cout << "File open error!" << endl;
        exit(1);
    }
    cout << "\nList after deletion:" << endl;
    deleteElements(inFileDel, listHead);
    displayList(listHead);
    inFileDel.close();

    return 0;
}
