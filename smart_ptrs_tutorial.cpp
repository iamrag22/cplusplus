#include <iostream>
#include <memory>
#include <vector>

using namespace std;

void pass_unique_ptr_by_value(unique_ptr<int> i){
    (*i)+=1;
}

void pass_unique_ptr_by_reference(unique_ptr<int> & i){
    (*i)+=1;
    cout << "Inside pass_unique_ptr_by_reference " << *i << endl;
}

void update_using_shared_ptr(shared_ptr<int> i){

    (*i)+=1;

    // This also increases the ref count by 1 in this scope. 
    // It will be decresed by 1 when the func scope ends.
    cout << "Ref count inside func: " <<  i.use_count() <<  endl;
}


void weak_ptr_example(){
    // Create shared ptr
    auto p1 = make_shared<int>(10);

    weak_ptr<int> wp1 = p1;
    
    //Weak ptr does not increase the ref count
    cout << "Ref count init "<< p1.use_count()<<"  " << wp1.use_count() <<  endl;

    // Check if weak_ptr is pointing to valid shared_ptr
    auto check_weakptr_ref = wp1.lock();
    cout << "Check Weak ptr ref in the beginning "<< check_weakptr_ref <<endl;
    
    // Create another shared_ptr in the inner scope
    {
        auto p2 = p1;
        wp1 = p2;

        p2.reset();
        
        // Ref count increases by 1 due to p2
        cout << "Ref count inner block "<< " p1: " << p1.use_count() << "  p2: "<< p2.use_count()<< "  wp1:  "<< wp1.use_count() <<  endl;
    }

    //Ref count decreases by 1 as p2 is out of scope and de allocated
    cout << "Ref count final "<< p1.use_count() << "  "<< wp1.use_count() <<endl;

    // Weak ptr ref is still valid as p1 exists
    auto check_weakptr_ref1 = wp1.lock();

    //  Valid memory location. Although it gets updated;
    cout << "Check Weak ptr reference final  "<< check_weakptr_ref << " "<< check_weakptr_ref << endl;
    

    if(check_weakptr_ref1){
        cout << "Weak ptr ref is valid " << endl;
    }
    else{
        cout << "Weak ptr ref is invalid " << endl;
    }

    // Reset the shared_ptr
    p1.reset();
    cout << "Ref count for shared ptr after reset "<< p1.use_count() << endl; // 0 count

    cout << wp1.expired() << "   "<< wp1.use_count() << "  "<<  wp1.lock() <<endl;
}


int main(int argc, char ** argv){
    auto p1 = make_unique<int>(100);
    cout<< *p1 << endl;
    
    // This will give a compile error
    // As update_using_unique_ptr has a copy of p1 as the parameter
    //pass_unique_ptr_by_value(p1); 
    
    // This is valid as ref to unique_ptr is passed.
    pass_unique_ptr_by_reference(p1);

    auto p2 = make_shared<int>(15);
    auto p3 = p2;  // p2 and p3 share ownership
    // Number of references
    cout << "Num references : " << " p2: "<< p2.use_count() << " p3: "<< p3.use_count() << endl;
    update_using_shared_ptr(p2);

    // Both p2 and p3 have the same value (16)
    cout<<*p2 <<" " <<*p3 << endl;


    // Create another shared smart pointer in inner scope
    {

        auto p4 = p2;
        update_using_shared_ptr(p4);

        // All pointers have value updated to 17
        cout<<*p2 <<" " <<*p3 << " "<< *p4<< endl;
    }

    // p2 and p3 are still 17
    cout<<*p2 <<" " <<*p3 << endl;

    // Weak ptr example
    weak_ptr_example();

    return 0;
}

/*  SMART POINTERS
They manage memory allocation and deallocation on heap
They call new, malloc, free, delete internally
Less probability of ememory leaks
Exception safe

unique_ptr
  unique_ptr does not have copy semantics.
  Gets destroyed when the ptr goes out of scope
  Very less overhead
  It clearly states the intent that only instance of something is responsible for ownership of 
  a resource (including safely destroying it)
  From Stackoverflow:  https://stackoverflow.com/questions/37370732/why-should-i-use-an-stdunique-ptr-when-i-could-just-destroy-the-object-in-my-d
  So one huge advantage of std::unique_ptr is that it automatically handles resource management, yes, but 
  another one is that it plays nicely with copy and move semantics and doesn't work in unexpected ways. 
  That's one of the main reasons to use it. You can say what you mean - "I'm the only one who should know 
  about this thing, and you can't share it" - and the compiler will enforce it for you. 
  Enlisting the compiler to help you avoid mistakes is almost always a good idea.

  Use cases: When Functions need to return a new instance
    std::unique_ptr<Bar> doStuffBetter(int param) {
        return new Bar(param);
    }




shared_ptr
  Has copy semantics
  Gets destroyed only when there are 0 ref count on the ptr. So one of the ptr can go out of scope.
  Slightly more overhead
  Can still cause memory leaks if there are cyclic dependencies causing the shared_ptrs to never
  be deallocated

weak_ptr
 It has a reference to the shared ptr  and not the object/resource directly
 It can tell if the shared_ptr is valid/or deallocated using lock(), expired()
 It solves the dangling reference problem that can happen with shared_ptr
 It does not change the ref count of shared_ptr

 using & vs & unique_ptr
  
 #

 Stack ( contigious, faster memory  allocation, 1 cpu) vs Heap (non contigious, slower)
*/