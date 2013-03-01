#include <vector>
#include <cstdlib>

#ifndef X_MEMORY_H
#define X_MEMORY_H

using namespace std;


namespace X {
    class Memory {
        private:
            static vector<void*> pointers;
        public:

            Memory() {
            }

            ~Memory() {
            }


            static void* memory_alloc(unsigned int num_of_bytes) {
                void *p = (void*)malloc(num_of_bytes);
                pointers.push_back(p);
                return p;
            }

            static void add_pointer(void *p) {
                pointers.push_back(p);
            }

            static void memory_free_all() {
                for(vector<void*>::iterator it = pointers.begin(); it != pointers.end(); ++it) {
                    free(*it);
                }
            }
            
            static void memory_free(void *p) {
                
            }
    };
    vector<void*> Memory::pointers;

}
#endif
