// ++++++++++++++++POSIST CODING ROUND+++++++++++++++
//                      :)

#include<bits/stdc++.h>
using namespace std;
#define ll long long

//  =========================working node structure =====================:

struct node{
       
       //===================nested structure=================
      struct data{

         int ownid;  //owner id
         float val;   // floating point value
         string own_name; // owner_name
         unordered_map<int,pair<int,string>>mp; //hashing of the set( id->{value,name});  

      };
   ll int nodeNumber;  // node number
    node* nodeId;   // id of the node (node identifier)
    node* refnode;// parent node
    vector<node*>child_ref_node;  // vector of child reference nodes to that node
    node*genesis_refnode;   // reference to the genesis node


};


//    FUNCTIONALITY 4
//   ==================ENCRYPTION of the data==================

// encrypts the node 
string PosistRecord::  encrypt(string text, int s)
{
    string result = "";

    // traverse text
    for (int i=0;i<text.length();i++)
    {
        // apply transformation to each character
        // Encrypt Uppercase letters
        if (isupper(text[i]))
            result += char(int(text[i]+s-65)%26 +65);

    // Encrypt Lowercase letters
    else
        result += char(int(text[i]+s-97)%26 +97);
    }

    // Return the resulting string
    return result;
    }


// FUNCTIONALITY 6 TRANSFER OF  THE OWNERSHIP 
 
 bool PosistRecord:: tranfer_own(struct node nd,struct node new_user)
 {      

          // check is it is a valid user
          if( mp.find(nd.data->ownid)==mp.end())
          {
               return false;
          }

         // else put the encrypted info to the new user structure 
         // and ensure that ownership is given to that user

         int s=nd->ownerid;
	string own_id=to_string(s);
	 if(own_id!=decrypt(own_id,-4))
	 return false;
	string  text=nd->owner_name;
      if(owner_name!=decrypt(owner_name,-4))
      return false;

else {
	      new_user=nd;
	      return true;
}


 }



 // FUNCTIONALITY 6 TRANSFER OF  THE OWNERSHIP 
 
 bool PosistRecord:: editing_node(struct node nd,struct node new_user)
 {      

          // check is it is a valid user
          if( mp.find(nd.data->ownid)==mp.end())
          {
               return false;
          }

         // else put the encrypted info to the new user structure 
         // 
         int s=nd->ownerid;
	string own_id=to_string(s);
	 if(own_id!=decrypt(own_id,-4))
	 return false;
	string  text=nd->owner_name;
      if(owner_name!=decrypt(owner_name,-4))
      return false;

else {
	      new_user=nd;
	      return true;
}


 }


    // FUNCTIONALITY 4 DECRYPTION
    string PosistRecord:: decrypt(string text, int s)
{
    string result = "";

    // traverse text
    for (int i=0;i<text.length();i++)
    {
        // apply transformation to each character
        // Encrypt Uppercase letters
        if (isupper(text[i]))
            result += char(int(text[i]+s-65)%26 +65);

    // Encrypt Lowercase letters
    else
        result += char(int(text[i]+s-97)%26 +97);
    }

    // Return the resulting string
    return result;
    }


struct node PosistRecord:: encrypt(struct data nd ,map<int,pair<int,string> >mp;)
{
	
	// encrypt the  id
	int s=nd->ownerid;
	string own_id=to_string(s);
	 own_id=encrypt(own_id,4);
	string  text=nd->owner_name;
      owner_name=encrypt(owner_name,4);

      // mapping the encrypted data

     mp[own_id]=make_pair(owner_name,val);
    struct node->data->own_name=owner_name;
    node->data->own_id=own_id;
    return node->data;
}


// returns the decrypted node information
struct node PosistRecord::  encrypt(struct data nd ,map<int,pair<int,string> >mp)
{
	
	// decrypt the  id
	int s=nd->ownerid;
	string own_id=to_string(s);
	 own_id=decrypt(own_id,-4);
	string  text=nd->owner_name;
      owner_name=decrypt(owner_name,-4);

      // mapping the encrypted data

     mp[own_id]=make_pair(owner_name,val);
    struct node->data->own_name=owner_name;
    node->data->own_id=own_id;
    return node->data;
}

//  FUNCTIONALITY 5  verifying the owner
 bool  PosistRecord:: verifyowner(struct node){


 int s=nd->ownerid;
	string own_id=to_string(s);
	 if(own_id!=decrypt(own_id,-4))
	 return false;
	string  text=nd->owner_name;
      if(owner_name!=decrypt(owner_name,-4))
      return false;

      //  else mapping the encrypted data
      // and checking whether user exist or not
    
     if(mp.find(own_id)!=mp.end())
      {
             return true;
      }

      else return false;


 }


// FUNCTIONALITY OF EDITING A NODE
int PosistRecord:: updatetree(node *root)
{
    // Base cases
    if (!root)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return root->data;

    // Update left and right subtrees
    int leftsum  = updatetree(root->left);
    int rightsum = updatetree(root->right);

    // Add leftsum to current node
    root->data += leftsum;

    // Return sum of values under root
    return root->data + rightsum;
}



//================FUNCTIONALITY 8,9 &10==============
//LONGEST CHAIN OF  GENESIS NODE 

/* Compute the "maxDepth" of the structure -- the number of 
    nodes along the longest path from the root genesis node 
    down to the farthest  node.*/
    int maxi=INT_MIN;
int PosistRecord:: maxDepth(struct node* node) 
{  
   if (node==NULL) 
       return 0;
   else
   {
       /* compute the depth of each subtree */
       for(int i=0;i<v_size;++i)
       {
         int Depth += maxDepth(node->child_ref_node[i]);

       }
 if(Depth>maxi)
         maxi=Depth;
       return maxi;
       
      
 
   }
} 	

// ====================function to get new node where bool isgenesis is used to differentiate b/w genesis node and other nodes:================
//      FUNCTIONALITY 1,2,3  (BY THE USE OF CONSTRUCTOR AND INVOKING THIS FUNCTION )
node*   getNewNode(struct data nd, int node_number, node* node_Id, node*ref_node,vector<node*>childrefnode,node*genesisrefnode, bool isgenesis)
{ 
    node*temp= new node;
    //  ==============nested structure initialization================

    //DATA ENCRYPTION
      struct node->data d= encrypt(nd);
    temp->data->ownid=d.id;
    temp->data->val=d.val;
    temp->data->own_name=d.own_name;
    temp->data->mp[d.id]=make_pair(d.val,d.own_name);
    temp->nodeNumber=node_number;
    temp->nodeId=node_Id;
    temp->refnode=ref_node;
    temp.child_ref_node.clear();
    unsigned int v_size=childrefnode.size();
    for(int i=0;i<v_size();++i)
    {
         child_ref_node[i]=childrefnode;
    }
    // =========================assigns no parent to the Genesis Node  =============
    if(isgenesis)
    {
         temp->refnode=NULL;
         temp->genesis_refnode=temp;// making the genesis node refer to itself

    }
    else {
           temp->genesis_refnode=genesisrefnode;
    }
    return temp; // returns the reference to the newly created node
	
}
           // FUNCTIONALITY TO ADD VALIDITY TO THE COMPLETE STRUCTURE
// =================== Accounts for the validity of the complete structure =============
// ==================ensures that whenever we are appending to the records with a new child node our condition i.e (child_nodes_sum<=genesis_node)
bool PosistRecord:: checkvalidity(int val,int curr_sum, int genesis_node_val)
{ 
	if(curr_sum+val<=genesis_node_val)
	{
	    return true;
	}

	else return false;
}

class PosistRecord{
   
     int curr_sum; // stores the sum of all the nodes apart from the genesis root node

	    public:
	    // ==================constructor for the class=======================
    // ============creates a genesis node and initializes the curr_sum=0 to account for the validity of the complete structure ============
    // ====================using the fact that  genesis_sum>curr_sum====================

	PosistRecord(struct data d, int node_number, node* node_Id, node*ref_node,vector<node*>childrefnode,node*genesisrefnode, bool isgenesis);
	bool checkvalidity(int val,int curr_sum, int genesis_node_val);
	int maxDepth(struct node* node) ;
	int updatetree(node *root);
	struct node encrypt(struct data nd ,map<int,pair<int,string> >mp);
		struct node decrypt(struct data nd ,map<int,pair<int,string> >mp);
string decrypt(string text, int s);
string encrypt(string text, int s);
	 bool verifyowner(struct node);


};


PosistRecord:: PosistRecord(struct data d, int node_number, node* node_Id, node*ref_node,vector<node*>childrefnode,node*genesisrefnode, bool isgenesis)
{
     curr_sum=0;
    node* newNode=getNewNode(struct data d, int node_number, node* node_Id, node*ref_node,vector<node*>childrefnode,node*genesisrefnode,true);
    nodeId=newNode;
}






//==================Driving function====================// 
int main()
{
	 PosistRecord pr(struct data d, int node_number, node* node_Id, node*ref_node,vector<node*>childrefnode,node*genesisrefnode, bool isgenesis);
          // now call for class member function on the class object pr as desired  :)
}
