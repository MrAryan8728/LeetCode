/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
Node* copyRandomList(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    // Step 1: Initialize an empty unordered map
    unordered_map<Node*, Node*> mapping;

    // Step 2: Traverse the original linked list and create a new node for each original node
    Node* curr = head;
    while (curr != nullptr) {
        mapping[curr] = new Node(curr->val);
        curr = curr->next;
    }

    // Step 3: Store the mapping between original and copied nodes in the unordered map
    curr = head;
    while (curr != nullptr) {
        mapping[curr]->next = mapping[curr->next];
        mapping[curr]->random = mapping[curr->random];
        curr = curr->next;
    }

    // Step 4: Set the next and random pointers of the copied nodes
    return mapping[head];
}
};