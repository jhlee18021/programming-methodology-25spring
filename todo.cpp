#include "todo.h"
#include <stdexcept>


void TodoList::init() {
    // TODO: set size to 0 and all task pointers to nullptr
    size = 0;
    for (int i=0; i<MAX_TASKS; i++)
    {
        tasks[i] = nullptr;
    }
}

void TodoList::destroy() {
    // TODO: delete all tasks and reset pointers
    size = 0;
    for (int i=0; i<MAX_TASKS; i++)
    {
        delete[] tasks[i];
        tasks[i] = nullptr;
    }
}

int TodoList::string_length(const char* str) const {
    // TODO: return the number of characters before '\0'
    char now = str[0];
    int len = 0;
    while (now != '\0')
    {
        now = str[len ++];
    }
    return len;
}

void TodoList::string_copy(char* dest, const char* src) const {
    // TODO: copy characters from src to dest
    int now_ind = 0;
    while (src[now_ind] != '\0')
    {
        dest[now_ind] = src[now_ind++];
    }
    dest[now_ind] = '\0';
}

void TodoList::add_task(const char* task) {
    // TODO: if full, throw. otherwise allocate and copy new task
    if (size >= 32)
    {
        throw std::overflow_error("Addition underflow");
    }
    else
    {
        int len = string_length(task);
        char* new_task = new char[len+1];
        for (int i=0; i<len; i++)
        {
            new_task[i] = task[i];
        }
        new_task[len] = '\0';
        tasks[size] = new_task;
        size ++;
    }
}

void TodoList::remove_task(int index) {
    // TODO: check bounds, delete task, shift left
    if (index < 0 || index >= size)
    {
        throw std::range_error("out of bounds");
    }
    
    delete[] tasks[index];
    for (int i=index; i<size; i++)
    {
        tasks[i] = tasks[i+1];
    }
    size --;
}

const char** TodoList::get_pending_tasks(int& count) const {
    // TODO: set count and return task array
    // [[A], [ABCDEFG], ]
    // ABCEFG: char[6]
    // [ABCDEFG] : *char[6]
    // [[asdfa ], a[asf ]] --> **char

    count = 0;
    while (tasks[count] != nullptr)
    {
        count ++;
    }

    const char** new_lst = new const char*[size];
    for (int i=0; i<size; i++)
    {
        int now_len = string_length(tasks[i]);
        char *element = new char[now_len+1];
        for (int j=0; j<now_len; j++)
        {
            element[j] = tasks[i][j];
        }
        element[now_len] = '\0';
        new_lst[i] = element;
    }


    return new_lst;
}