#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

// Мы хотим, чтобы в структуре user хранились ссылки только на строчки из кучи.
typedef struct { char* addr; } string_heap ;

/*  Тип для идентификаторов пользователей
    и его спецификаторы ввода и вывода для printf */
typedef uint64_t uid;
#define PRI_uid PRIu64
#define SCN_uid SCNu64

enum city {C_SARATOV, C_MOSCOW, C_PARIS, C_LOS_ANGELES, C_OTHER};

/*  Массив, где элементам перечисления сопоставляются их текстовые представления */
const char* city_string[] = {
  [C_SARATOV] = "Saratov",
  [C_MOSCOW] = "Moscow",
  [C_PARIS] = "Paris",
  [C_LOS_ANGELES] = "Los Angeles",
  [C_OTHER] = "Other"
};


struct user {
  const uint64_t id;
  const string_heap name;
  enum city city;
};

//helping funcs
int user_id_comparer(const struct user* x, const struct user* y){
    if((*x).id>(*y).id)return 1;
    if((*x).id>(*y).id)return -1;
    return 0;
}

int user_id_void_comparer(const void* _x, const void* _y){
    return user_id_comparer(_x, _y);
}

int user_name_comparer(const struct user* x, const struct user* y){
    return strcmp((*x).name.addr, (*y).name.addr);
}

int user_name_void_comparer(const void* _x, const void* _y){
    return user_name_comparer(_x, _y);
}


int user_city_comparer(const struct user* x, const struct user* y){
    return strcmp(city_string[(*x).city], (city_string[(*y).city]));
}

int user_city_void_comparer(const void* _x, const void* _y){
    return user_city_comparer(_x, _y);
}


/* Сортировать массив пользователей по полю uid по возрастанию */
void users_sort_uid(struct user users[], size_t sz) {
    qsort(users, sz, sizeof(struct user), user_id_void_comparer);
}

/* Сортировать массив пользователей по полю name */
/* Порядок строк лексикографический; можно использовать компаратор
   строк -- стандартную функцию strcmp */
void users_sort_name(struct user users[], size_t sz) {
  qsort(users, sz, sizeof(struct user), user_name_void_comparer);
}

/* Сортировать массив по _текстовому представлению_ города */
void users_sort_city(struct user users[], size_t sz) {
    qsort(users, sz, sizeof(struct user), user_city_void_comparer);
}

void print_users(struct user users[], size_t sz){
    for(size_t k =0; k<sz; k++){
        printf("%"PRId64" ", users[k].id);
        printf("%s ", users[k].name.addr);
        printf("%u%s\n" , users[k].city, city_string[users[k].city]);
    }
}

int main(){
    struct user users[]={
        {2, "Sasha", C_MOSCOW},
        {4, "Olga", C_SARATOV},
        {0, "Elena", C_PARIS},
        {1, "Denis", C_LOS_ANGELES},
        {3, "Tanya", C_OTHER},
    };
    size_t size = sizeof(users)/sizeof(users[0]);
    users_sort_uid(users, size);
    print_users(users, size);
    printf("\n");
    users_sort_name(users, size);
    print_users(users, size);
    printf("\n");
    users_sort_city(users, size);
    print_users(users, size);
}
