#ifndef UPR_PROJEKT_HTMLWRITER_H
#define UPR_PROJEKT_HTMLWRITER_H

void writeHeader(FILE* file);
void writeFooter(FILE* file);
void writeTableTop(FILE* file);
void writeTableMiddle(FILE* file);
void writeTableBottom(FILE* file);
void writeTableTh(FILE* file, char* string);
void writeTableTd(FILE* file, char* string);
void writeTableTrBeginning(FILE* file);
void writeTableTrEnd(FILE* file);


#endif //UPR_PROJEKT_HTMLWRITER_H
