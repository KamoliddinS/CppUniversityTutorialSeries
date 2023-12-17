#include <iostream>
#include <memory>  // Include for std::shared_ptr


using namespace std;
class Resource {
public:
    Resource() { std::cout << "Resource acquired.\n"; }
    ~Resource() { std::cout << "Resource destroyed.\n"; }
    void doWork() { std::cout << "Resource is working.\n"; }
};

void processWithUniquePtr() {
    std::unique_ptr<Resource> uniqueEx = std::make_unique<Resource>();
    uniqueEx->doWork();


    // it is smart pointer we do'nt have to delete resource it will be detelet automatically 
}



int main() {

    cout<< "Before calling processWithUniquePtr"<<endl;
    processWithUniquePtr();
    
    cout<< " After calling processWithUniquePtr"<< endl;


    std::unique_ptr<Resource> uniquePtr1 = std::make_unique<Resource>();
    // std::unique_ptr<Resource> uniquePtr2 = uniquePtr1;   ///I cannot share it because it is unique 

    std::shared_ptr<Resource> sharedPtr1 =std::make_shared<Resource> ();
    std::shared_ptr<Resource> sharedPtr2 = sharedPtr1; // you can do this because it is shared pointer 


    std::weak_ptr<Resource> weakPtr = sharedPtr1;

    // Lock the weak_ptr to create a temporary shared_ptr
    if (auto tempSharedPtr = weakPtr.lock()) {
        std::cout << "Managed object is still alive.\n";
        tempSharedPtr->doWork();
    } else {
        std::cout << "Managed object has been destroyed.\n";
    }
    sharedPtr1.reset();
    sharedPtr2.reset();

    if (auto tempSharedPtr = weakPtr.lock()) {
        std::cout << "Managed object is still alive.\n";
        tempSharedPtr->doWork();
    } else {
        std::cout << "Managed object has been destroyed.\n";
    }



    return 0;
}
