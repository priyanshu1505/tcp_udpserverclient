#include<stdio.h>
#include<jansson.h>
#include<string.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Invalid Format! <FirstName> <LastName>\n");
        return 1;
    }
    
    json_t* obj = json_object(), *data;
    json_t* arr = json_array();
    int i = 1, count = 1, datalen = 0;

    datalen = argc;
    printf("%d entries made.\n", datalen / 2);

    json_object_set_new(obj, "employees", arr);
    
    for(i = 1; i <= (datalen / 2); i++) {
        data = json_object();
        json_array_append_new(arr, data);
    
        json_object_set_new(data, "firstName", json_string(argv[count++]));

        json_object_set_new(data, "lastName", json_string(argv[count++]));
    }

    int check = json_dump_file(obj, "sample.json", 0);
    
    if(check == 0)
        printf("File successfully dumped!\n");
    else
        printf("Error! File cannot be dumped\n");
    
    return 0;
}
