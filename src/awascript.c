#include <stdio.h>
#include <stddef.h>

#define VALID_AWA 0
#define INVALID_AWA -1

#define LETTER_BITMASK 0b00011111

static const char valid_inputs[] = "AWaw";
static const char bf_chars[] = "><+-.,[]";

static const char awa[] = "awa";

struct AwaState{
    size_t read;
    int current_token;
};

int process_character(struct AwaState *awastate, char c){
    for(size_t i=0; i<sizeof(valid_inputs)-1; ++i){
        if(c==valid_inputs[i]){
            goto meaningful_char;
        }
    }
    //non-awa character
    //ignore as whitespace
    return 0;

meaningful_char:
    ;
    int current_token_letters_read = awastate->read % 3;
    if((c & LETTER_BITMASK) != (awa[current_token_letters_read] & LETTER_BITMASK)){
        return INVALID_AWA;
    }

    int is_uppercase = (~c>>5) & 1;
    awastate->current_token <<= 1;
    awastate->current_token |= is_uppercase;
    awastate->read++;

    if(!(current_token_letters_read == 2)){
        //awa not finished yet
        return 0;
    }

    putchar(bf_chars[awastate->current_token]);
    awastate->current_token = 0;
    return 0;

}

int main(){
    struct AwaState awa = {0,0};
    char c;
    int error = 0;
    do{
        c = getchar();
        error = process_character(&awa, c);
    }
    while(c!=EOF && error == 0);

    if(error == INVALID_AWA){
        fputs("\nInvalid Awa.", stderr);
    }

    putchar('\n');

    return 0;
}
