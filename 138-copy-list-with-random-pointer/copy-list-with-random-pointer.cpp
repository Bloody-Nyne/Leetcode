class Solution {
    unordered_map<Node*,Node*> hash;
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* oldNode = head;
        Node* newNode = new Node(oldNode->val);
        hash[oldNode] = newNode;
        while(oldNode){
            newNode->next = getCopyNode(oldNode->next);
            newNode->random = getCopyNode(oldNode->random);
            oldNode = oldNode->next;
            newNode = newNode->next;
        }
        return hash[head];
    }
private:
    Node* getCopyNode(Node* node){
        if(!node) return NULL;
        if(hash.find(node) != hash.end()) return hash[node];
        hash[node] = new Node(node->val);
        return hash[node];
    }
};