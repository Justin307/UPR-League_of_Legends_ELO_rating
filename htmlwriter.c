#include <stdio.h>

#include "htmlwriter.h"

void writeHtmlHeader(FILE* file)
{
    if(file != NULL)
    {
        char* template = "<!DOCTYPE html>\n<html>\n<head>\n\t<meta charset=\"utf-8\">\n\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n\t<link href=\"https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css\" rel=\"stylesheet\" integrity=\"sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3\" crossorigin=\"anonymous\">\n</head>\n<body class=\"bg-dark\">\n";
        fputs(template, file);
    }
}

void WriteHtmlFooter(FILE* file)
{
    if(file != NULL)
    {
        char* template = "</body>\n</html>";
        fputs(template, file);
    }
}

void writeTableTop(FILE* file)
{
    if(file != NULL)
    {
        char* template = "<div class=\"m-5 table-responsive\">\n\t<table class=\"table table-dark table-striped table-hover\">\n\t\t<thead>\n\t\t\t<tr class=\"table-active\">\n";
        fputs(template, file);
    }
}

void writeTableMiddle(FILE* file)
{
    if(file != NULL)
    {
        char* template = "\t\t\t</tr>\n\t\t</thead>\n\t\t<tbody>\n";
        fputs(template, file);
    }
}

void writeTableBottom(FILE* file)
{
    if(file != NULL)
    {
        char* template = "\t\t</tbody>\n\t</table>\n</div>\n";
        fputs(template, file);
    }
}

void writeTableTh(FILE* file, char* string)
{
    if(file != NULL)
    {
        char* template1 = "\t\t\t\t<th>";
        char* template2 = "</th>\n";
        fprintf(file,"%s%s%s",template1,string,template2);
    }
}

void writeTableTd(FILE* file, char* string)
{
    if(file != NULL)
    {
        char* template1 = "\t\t\t\t<td>";
        char* template2 = "</td>\n";
        fprintf(file,"%s%s%s",template1,string,template2);
    }
}

void writeTableTdBeginning(FILE* file)
{
    if(file != NULL)
    {
        char* template = "\t\t\t\t<td>";
        fputs(template,file);
    }
}

void writeTableTdEnd(FILE* file)
{
    if(file != NULL)
    {
        char* template = "</td>\n";
        fputs(template,file);
    }
}

void writeTableTrBeginning(FILE* file)
{
    if(file != NULL)
    {
        char *template = "\t\t\t<tr>\n";
        fputs(template, file);
    }
}

void writeTableTrEnd(FILE* file)
{
    if(file != NULL)
    {
        char *template = "\t\t\t</tr>\n";
        fputs(template, file);
    }
}

void writeInt(FILE* file, int x)
{
    if(file != NULL)
    {
        fprintf(file,"%d",x);
    }
}

void writeChar(FILE* file, char c)
{
    if(file != NULL)
    {
        fputc(c, file);
    }
}


