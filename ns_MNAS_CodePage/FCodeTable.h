#ifndef CODETABLE_H
#define CODETABLE_H

/**
    Класс CodeTable содержит набор утилит для преобразования кодировок файлов.
*/

class MNASOFT_EXPORT CodeTable
{
    unsigned char tbl[256];
    int from_to_code;
public:
    CodeTable();
/**1 - Win cp=1251->Dos cp=866;  2 - Dos cp=866->Win cp=1251; 3 - Win cp=1251 -> Koi8-r; 4 - Koi8-r -> Win cp=1251.*/
    CodeTable(int From_to_code);
    char trans_ch(char ch);
    char * trans_str(char * a, char * rez);
    int  set_code_tbl(int From_to_code);
    int  get_code_tbl(){return from_to_code;}
    ~CodeTable();
};

#endif //CODETABLE_H
