#ifndef UPR_PROJEKT_HTMLWRITER_H
#define UPR_PROJEKT_HTMLWRITER_H

void writeHtmlHeader(FILE* file);
void WriteHtmlFooter(FILE* file);
void writeTableTop(FILE* file);
void writeTableMiddle(FILE* file);
void writeTableBottom(FILE* file);
void writeTableTh(FILE* file, char* string);
void writeTableTd(FILE* file, char* string);
void writeTableTdBeginning(FILE* file);
void writeTableTdEnd(FILE* file);
void writeTableTrBeginning(FILE* file);
void writeTableTrEnd(FILE* file);
void writeInt(FILE* file, int x);
void writeFloat(FILE* file, float x);
void writeChar(FILE* file, char c);


#endif //UPR_PROJEKT_HTMLWRITER_H
