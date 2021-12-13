#include "HEADER.h"

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

char *sdup(char *original) {
    char *duplicate = malloc(strlen(original) + 1);
    if (duplicate == NULL) { return NULL; }

    strcpy(duplicate, original);
    return duplicate;
}

// remove tokken from string str, tokken
void rmtok(char *X, char *Y) {
  char *m;
  int len = strlen(Y);
  while ((m = strstr(X, Y))) {
    *m = '\0';
    strcat(X, m+len);
    }
}

// replace one string at a time src, str, new
void rplstr(char *X, char *Y, char *Z){
     char *q;
     if ((q = strstr(X, Y)) == NULL) {
         return;
     }
     int y_len = strlen(Y);
     int z_len = strlen(Z);
     int t_len = strlen(q+y_len);
     memmove(q+z_len,q+y_len,t_len+1);
     memcpy(q, Z, z_len);
}

// replace all src, str, new
void strmagic(char *X, char *Y, char *Z){
char *w = strstr(X, Y);
  if(w){
  int len = strlen(X)+strlen(Z)-strlen(Y);
  char r[len];
  memset(r, 0, len);
    if(w >= X){
    strncpy(r, X, w-X);
    r[w-X]='\0';
    strncat(r, Z, strlen(Z));
    strncat(r, w+strlen(Y), w+strlen(Y)-X+strlen(X));
    strcpy(X, r);
    strmagic(w+strlen(Z), Y, Z);
    }
  }
}

void strstrip(char *X, char *Y){
  strtok(X, "\n");
  rmtok(X, Y);
  rmtok(X, "'");
  rmtok(X, "\"");
  rmtok(X, "(");
  rmtok(X, ")");
  rmtok(X, "{");
  rmtok(X, "}");
  rmtok(X, ",");
}

char *pkg(){
char *dup = sdup(data);
char *pkg = strstr(dup, PKG);
  if(!pkg){
  return strdup("");
  } else {
  strstrip(pkg, PKG);
  }
return pkg;
}

char *ver(){
char *dup = sdup(data);
char *ver = strstr(dup, VER);
  if(!ver){
  return strdup("");
  } else {
  strstrip(ver, VER);
  }
return ver;
}

char *rel(){
char *dup = sdup(data);
char *rel = strstr(dup, REL);
  if(!rel){
  return strdup("");
  } else {
  strstrip(rel, REL);
  }
return rel;
}

char *epc(){
char *dup = sdup(data);
char *epc = strstr(dup, EPC);
  if(!epc){
  return strdup("");
  } else {
  strstrip(epc, EPC);
  }
return epc;
}

char *dsc(){
char *dup = sdup(data);
char *dsc = strstr(dup, DSC);
  if(!dsc){
  return strdup("");
  } else {
  strstrip(dsc, DSC);
  }
return dsc;
}

char *ark(){
char *dup = sdup(data);
char *ark = strstr(dup, ARK);
  if(!ark){
  return strdup("");
  } else {
  strstrip(ark, ARK);
  }
return ark;
}

char *url(){
char *dup = sdup(data);
char *url = strstr(dup, URL);
  if(!url){
  return strdup("");
  } else {
  strstrip(url, URL);
  }
return url;
}

char *lic(){
char *dup = sdup(data);
char *lic = strstr(dup, LIC);
  if(!lic){
  return strdup("");
  } else {
  strstrip(lic, LIC);
  }
return lic;
}

char *grp(){
char *dup = sdup(data);
char *grp = strstr(dup, GRP);
  if(!grp){
  return strdup("");
  } else {
  strstrip(grp, GRP);
  }
return grp;
}

char *dep(){
char *dup = sdup(data);
char *dep = strstr(dup, DEP);
  if(!dep){
  return strdup("");
  } else {
  strstrip(dep, DEP);
  }
return dep;
}

char *odp(){
char *dup = sdup(data);
char *odp = strstr(dup, ODP);
  if(!odp){
  return strdup("");
  } else {
  strstrip(odp, ODP);
  }
return odp;
}

char *mdp(){
char *dup = sdup(data);
char *mdp = strstr(dup, MDP);
  if(!mdp){
  return strdup("");
  } else {
  strstrip(mdp, MDP);
  }
return mdp;
}

char *cdp(){
char *dup = sdup(data);
char *cdp = strstr(dup, CDP);
  if(!cdp){
  return strdup("");
  } else {
  strstrip(cdp, CDP);
  }
return cdp;
}

char *prv(){
char *dup = sdup(data);
char *prv = strstr(dup, PRV);
  if(!prv){
  return strdup("");
  } else {
  strstrip(prv, PRV);
  }
return prv;
}

char *con(){
char *dup = sdup(data);
char *con = strstr(dup, CON);
  if(!con){
  return strdup("");
  } else {
  strstrip(con, CON);
  }
return con;
}

char *rpl(){
char *dup = sdup(data);
char *rpl = strstr(dup, RPL);
  if(!rpl){
  return strdup("");
  } else {
  strstrip(rpl, RPL);
  }
return rpl;
}

char *bac(){
char *dup = sdup(data);
char *bac = strstr(dup, BAC);
  if(!bac){
  return strdup("");
  } else {
  strstrip(bac, BAC);
  }
return bac;
}

char *opt(){
char *dup = sdup(data);
char *opt = strstr(dup, OPT);
  if(!opt){
  return strdup("");
  } else {
  strstrip(opt, OPT);
  }
return opt;
}

char *ins(){
char *dup = sdup(data);
char *ins = strstr(dup, INS);
  if(!ins){
  return strdup("");
  } else {
  strstrip(ins, INS);
  }
return ins;
}

char *chg(){
char *dup = sdup(data);
char *chg = strstr(dup, CHG);
  if(!chg){
  return strdup("");
  } else {
  strstrip(chg, CHG);
  }
return chg;
}

char *src(){
char *dup = sdup(data);
char *src = strstr(dup, SRC);
  if(!src){
  return strdup("");
  } else {
  strstrip(src, SRC);
  }
return src;
}

char *nex(){
char *dup = sdup(data);
char *nex = strstr(dup, NEX);
  if(!nex){
  return strdup("");
  } else {
  strstrip(nex, NEX);
  }
return nex;
}

char *vpg(){
char *dup = sdup(data);
char *vpg = strstr(dup, VPG);
  if(!vpg){
  return strdup("");
  } else {
  strstrip(vpg, VPG);
  }
return vpg;
}

char *md5(){
char *dup = sdup(data);
char *md5 = strstr(dup, MD5);
  if(!md5){
  return strdup("");
  } else {
  strstrip(md5, MD5);
  }
return md5;
}

char *sh1(){
char *dup = sdup(data);
char *sh1 = strstr(dup, SH1);
  if(!sh1){
  return strdup("");
  } else {
  strstrip(sh1, SH1);
  }
return sh1;
}

char *sh2(){
char *dup = sdup(data);
char *sh2 = strstr(dup, SH2);
  if(!sh2){
  return strdup("");
  } else {
  strstrip(sh2, SH2);
  }
return sh2;
}

char *sh5(){
char *dup = sdup(data);
char *sh5 = strstr(dup, SH5);
  if(!sh5){
  return strdup("");
  } else {
  strstrip(sh5, SH5);
  }
return sh5;
}

int main(void){
openfile();
char *a = pkg();
char *b =ver();
char *c = rel();
char *d = epc();
char *e = dep();

printf("%s\n", a);
printf("%s\n", b);
printf("%s\n", c);
printf("%s\n", d);
printf("%s\n", e);

printf("%s\n", a);
printf("%s\n", b);
printf("%s\n", c);
printf("%s\n", d);
printf("%s\n", e);

printf("%s\n", a);
printf("%s\n", b);
printf("%s\n", c);
printf("%s\n", d);
printf("%s\n", e);

return 0;
}
