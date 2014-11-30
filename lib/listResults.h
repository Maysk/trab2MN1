typedef struct NodeResult_{
    Result *result;
    NodeResult_ *next;
} NodeResult;


class ListResults{
    NodeResult *first;
    NodeResult *last;
    int lenght;
public:

    ListResults();

    ~ListResults();

    bool isEmpty();

    void push(Result* result);

    Result *pop();

    int getLength();

    std::string toString();
};
