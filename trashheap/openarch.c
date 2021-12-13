#include "pkgd.h"

FILE *fptr;
long length;
char *data = 0;

char *openfile(){
fptr = fopen(FILENAME, "rb");
if(fptr){
  fseek(fptr, 0, SEEK_END);
  length = ftell(fptr);
  fseek(fptr, 0, SEEK_SET);
  data = malloc(length);
  if(data)
  {
    fread(data, 1, length, fptr);
  }
  fclose(fptr);
}

if(data){
  

  //printf("%s", ver);
}
return data;
}

void removestr(char *string, char *sub) {
  char *match;
  int len = strlen(sub);
  while ((match = strstr(string, sub))) {
    *match = '\0';
    strcat(string, match+len);
    }
}

void replacestr(char *line, char *search, char *replace){
     char *sp;
     if ((sp = strstr(line, search)) == NULL) {
         return;
     }
     int search_len = strlen(search);
     int replace_len = strlen(replace);
     int tail_len = strlen(sp+search_len);
     memmove(sp+replace_len,sp+search_len,tail_len+1);
     memcpy(sp, replace, replace_len);
}

void strreplace(char *src, char *str, char *rep){
char *p = strstr(src, str);
  if(p){
  int len = strlen(src)+strlen(rep)-strlen(str);
  char r[len];
  memset(r, 0, len);
    if(p >= src){
    strncpy(r, src, p-src);
    r[p-src]='\0';
    strncat(r, rep, strlen(rep));
    strncat(r, p+strlen(str), p+strlen(str)-src+strlen(src));
    strcpy(src, r);
    strreplace(p+strlen(rep), str, rep);
    }
  }
}

char *pkg(){
char *pkg = strstr(data, PKG);
  if(!pkg){
  return strdup("");
  } else {
  strtok(pkg, "\n");
  removestr(pkg, PKG);
  }
return pkg;
}

char *ver(){
char *ver = strstr(data, VER);
  if(!ver){
  return strdup("");
  } else {
  strtok(ver, "\n");
  removestr(ver, VER);
  }
return ver;
}

char *rel(){
char *rel = strstr(data, REL);
  if(!rel){
  return strdup("");
  } else {
  strtok(rel, "\n");
  removestr(rel, REL);
  }
return rel;
}

char *epc(){
char *epc = strstr(data, EPC);
  if(!epc){
  return strdup("");
  } else {
  strtok(epc, "\n");
  removestr(epc, EPC);
  }
return epc;
}

char *dsc(){
char *dsc = strstr(data, DSC);
  if(!dsc){
  return strdup("");
  } else {
  strtok(dsc, "\n");
  removestr(dsc, DSC);
  removestr(dsc, "'");
  }
return dsc;
}

char *ark(){
char *ark = strstr(data, ARK);
  if(!ark){
  return strdup("");
  } else {
  strtok(ark, "\n");
  removestr(ark, ARK);
  removestr(ark, "'");
  removestr(ark, "(");
  removestr(ark, ")");
  }
return ark;
}

char *url(){
char *url = strstr(data, URL);
  if(!url){
  return strdup("");
  } else {
  strtok(url, "\n");
  removestr(url, URL);
  removestr(url, "'");
  removestr(url, "\"");
  removestr(url, "(");
  removestr(url, ")");
  }
return url;
}

char *lic(){
char *lic = strstr(data, LIC);
  if(!lic){
  return strdup("");
  } else {
  strtok(lic, "\n");
  removestr(lic, LIC);
  removestr(lic, "'");
  removestr(lic, "\"");
  removestr(lic, "(");
  removestr(lic, ")");
  }
return lic;
}

char *grp(){
char *grp = strstr(data, GRP);
  if(!grp){
  return strdup("");
  } else {
  strtok(grp, "\n");
  removestr(grp, GRP);
  removestr(grp, "'");
  removestr(grp, "\"");
  removestr(grp, "(");
  removestr(grp, ")");
  }
return grp;
}

char *dep(){
char *dep = strstr(data, DEP);
  if(!dep){
  return strdup("");
  } else {
  strtok(dep, "\n");
  removestr(dep, DEP);
  removestr(dep, "'");
  removestr(dep, "\"");
  removestr(dep, "(");
  removestr(dep, ")");
  }
return dep;
}

char *odp(){
char *odp = strstr(data, ODP);
  if(!odp){
  return strdup("");
  } else {
  strtok(odp, "\n");
  removestr(odp, ODP);
  removestr(odp, "'");
  removestr(odp, "\"");
  removestr(odp, "(");
  removestr(odp, ")");
  }
return odp;
}

char *mdp(){
char *mdp = strstr(data, MDP);
  if(!mdp){
  return strdup("");
  } else {
  strtok(mdp, "\n");
  removestr(mdp, MDP);
  removestr(mdp, "'");
  removestr(mdp, "\"");
  removestr(mdp, "(");
  removestr(mdp, ")");
  }
return mdp;
}

char *cdp(){
char *cdp = strstr(data, CDP);
  if(!cdp){
  return strdup("");
  } else {
  strtok(cdp, "\n");
  removestr(cdp, CDP);
  removestr(cdp, "'");
  removestr(cdp, "\"");
  removestr(cdp, "(");
  removestr(cdp, ")");
  }
return cdp;
}

char *prv(){
char *prv = strstr(data, PRV);
  if(!prv){
  return strdup("");
  } else {
  strtok(prv, "\n");
  removestr(prv, PRV);
  removestr(prv, "'");
  removestr(prv, "\"");
  removestr(prv, "(");
  removestr(prv, ")");
  }
return prv;
}

char *con(){
char *con = strstr(data, CON);
  if(!con){
  return strdup("");
  } else {
  strtok(con, "\n");
  removestr(con, CON);
  removestr(con, "'");
  removestr(con, "\"");
  removestr(con, "(");
  removestr(con, ")");
  }
return con;
}

char *rpl(){
char *rpl = strstr(data, RPL);
  if(!rpl){
  return strdup("");
  } else {
  strtok(rpl, "\n");
  removestr(rpl, RPL);
  removestr(rpl, "'");
  removestr(rpl, "\"");
  removestr(rpl, "(");
  removestr(rpl, ")");
  }
return rpl;
}

char *bac(){
char *bac = strstr(data, BAC);
  if(!bac){
  return strdup("");
  } else {
  strtok(bac, "\n");
  removestr(bac, BAC);
  removestr(bac, "'");
  removestr(bac, "\"");
  removestr(bac, "(");
  removestr(bac, ")");
  }
return bac;
}

char *opt(){
char *opt = strstr(data, OPT);
  if(!opt){
  return strdup("");
  } else {
  strtok(opt, "\n");
  removestr(opt, OPT);
  removestr(opt, "'");
  removestr(opt, "\"");
  removestr(opt, "(");
  removestr(opt, ")");
  }
return opt;
}

char *ins(){
char *ins = strstr(data, INS);
  if(!ins){
  return strdup("");
  } else {
  strtok(ins, "\n");
  removestr(ins, INS);
  removestr(ins, "'");
  removestr(ins, "\"");
  removestr(ins, "(");
  removestr(ins, ")");
  }
return ins;
}

char *chg(){
char *chg = strstr(data, CHG);
  if(!chg){
  return strdup("");
  } else {
  strtok(chg, "\n");
  removestr(chg, CHG);
  removestr(chg, "'");
  removestr(chg, "\"");
  removestr(chg, "(");
  removestr(chg, ")");
  }
return chg;
}

char *src(){
char *src = strstr(data, SRC);
  if(!src){
  return strdup("");
  } else {
  strtok(src, "\n");
  removestr(src, SRC);
  removestr(src, "'");
  removestr(src, "\"");
  removestr(src, "(");
  removestr(src, ")");
  removestr(src, "{");
  removestr(src, "}");
  replacestr(src, ",.asc", "");
  removestr(src, ",.asc");
  replacestr(src, "$pkgname-$pkgver", pkg());
  }
return src;
}

char *nex(){
char *nex = strstr(data, NEX);
  if(!nex){
  return strdup("");
  } else {
  strtok(nex, "\n");
  removestr(nex, NEX);
  removestr(nex, "'");
  removestr(nex, "\"");
  removestr(nex, "(");
  removestr(nex, ")");
  }
return nex;
}

char *vpg(){
char *vpg = strstr(data, VPG);
  if(!vpg){
  return strdup("");
  } else {
  strtok(vpg, "\n");
  removestr(vpg, VPG);
  removestr(vpg, "'");
  removestr(vpg, "\"");
  removestr(vpg, "(");
  removestr(vpg, ")");
  }
return vpg;
}

char *md5(){
char *md5 = strstr(data, MD5);
  if(!md5){
  return strdup("");
  } else {
  strtok(md5, "\n");
  removestr(md5, MD5);
  removestr(md5, "'");
  removestr(md5, "\"");
  removestr(md5, "(");
  removestr(md5, ")");
  }
return md5;
}

char *sh1(){
char *sh1 = strstr(data, SH1);
  if(!sh1){
  return strdup("");
  } else {
  strtok(sh1, "\n");
  removestr(sh1, SH1);
  removestr(sh1, "'");
  removestr(sh1, "\"");
  removestr(sh1, "(");
  removestr(sh1, ")");
  }
return sh1;
}

char *sh2(){
char *sh2 = strstr(data, SH2);
  if(!sh2){
  return strdup("");
  } else {
  strtok(sh2, "\n");
  removestr(sh2, SH2);
  removestr(sh2, "'");
  removestr(sh2, "\"");
  removestr(sh2, "(");
  removestr(sh2, ")");
  }
return sh2;
}

char *sh5(){
char *sh5 = strstr(data, SH5);
  if(!sh5){
  return strdup("");
  } else {
  strtok(sh5, "\n");
  removestr(sh5, SH5);
  removestr(sh5, "'");
  removestr(sh5, "\"");
  removestr(sh5, "(");
  removestr(sh5, ")");
  }
return sh5;
}

int main(void){
openfile();
char *a = dep();
printf("%s\n", a);
return 0;
}
