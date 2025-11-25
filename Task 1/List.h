Try AI directly in your favorite apps … Use Gemini to generate drafts and refine content, plus get Gemini Pro with access to Google's next-gen AI for EGP 699.99 EGP 0 for 1 month
class List {

    
    class node {
    public:
        int key;
        char data;
        node *next;
    }; 
    node* head, cursor, prev;

    public:
   
    List();
    ~List();

    bool listIsEmpty() const; 
	bool curIsEmpty() const; 
	void toFirst(); 
	bool atFirst() const;
	void advance(); 
    void toEnd(); 
	bool atEnd() const;
	int  listSize() const;
	void updateData (const char & ); 
    void updateKey (const char & ); 
	char retrieveData () const;
    void retrieveData (const char &);
	void insertFirst (const int &, const char & ); 
	void insertAfter (const int &, const char & );
	void insertBefore (const int &, const char & );
	void insertEnd (const int &, const char & );
	void deleteNode();
	void deleteFirst();
	void deleteEnd();
	void makeListEmpty(); 
	bool search (const int & ); 
	void orderInsert(const int &, const char & );
	void traverse();
    
};