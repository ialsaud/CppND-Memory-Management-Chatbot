#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include <iostream>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;
    std::string _filename;


    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot(); // destructor (1/5)

    //// STUDENT CODE
    ////
    ChatBot(const ChatBot& other); // copy constructor (2/5)
    ChatBot& operator=(const ChatBot& other); // copy operator (3/5)
    ChatBot(ChatBot&& other); // move constructor (4/5)
    ChatBot& operator=(ChatBot&& other); // move operator (5/5)
    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    wxBitmap *GetImageHandle() { 
        std::cout<<"giving out a handle to image!!\n";
        return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */