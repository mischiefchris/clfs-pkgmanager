#include "pkgd.h"

FILE *fptr;
long length;
char *data = 0;
char *pkgi;
char *veri;
char *reli;
char *ephi;
char *desi;
char *arki;
char *urli;
char *lici;
char *grpi;
char *depi;
char *mepi;
char *cepi;
char *oepi;
char *cnfi;
char *rpli;
char *baci;
char *opti;
char *scri;
char *srci;
char *noei;
char *vpgi;
char *md5i;
char *sh1i;
char *sh2i;
char *sh5i;

// create a duplicate of buildscript: src
char *datadup(char *dupi) {
    char *dp = malloc(strlen(dupi) + 1);
    if (dp == NULL) { return NULL; }
    strcpy(dp, dupi);
    return dp;
}

// remove tokken from string: str, tokken
void rmtok(char *X, char *Y) {
  char *m;
  int len = strlen(Y);
  while ((m = strstr(X, Y))) {
    *m = '\0';
    strcat(X, m+len);
    }
}

// replace one string at a time: src, str, new
void repl(char *X, char *Y, char *Z){
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

// replace all matching strings: src, str, new
void replall(char *X, char *Y, char *Z){
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
    replall(w+strlen(Z), Y, Z);
    }
  }
}

// strips string of delimiters: str, strip item
void stripstr(char *X, char *Y){
  rmtok(X, Y);
  rmtok(X, "'");
  rmtok(X, "\"");
  rmtok(X, "(");
  rmtok(X, ")");
  rmtok(X, "{");
  rmtok(X, "}");
  rmtok(X, ",");
}

char *strstrstrip(char *x, char *y){
  char *dup = datadup(data);
  char *xy = strstr(dup, x);
  if(!xy){
  return strdup("");
  } else {
  strtok(xy, "\n");
  stripstr(xy, y);
  }
return xy;
}

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
  // think of something
  pkgi = strstrstrip(PKG, PKG);
  veri = strstrstrip(VER, VER);
  reli = strstrstrip(REL, REL);
  ephi = strstrstrip(EPH, EPH);
  desi = strstrstrip(DES, DES);
  arki = strstrstrip(ARK, ARK);
  urli = strstrstrip(URL, URL);
  lici = strstrstrip(LIC, LIC);
  grpi = strstrstrip(GRP, GRP);
  depi = strstrstrip(DEP, DEP);
  mepi = strstrstrip(MEP, MEP);
  cepi = strstrstrip(CEP, CEP);
  oepi = strstrstrip(OEP, OEP);
  cnfi = strstrstrip(CNF, CNF);
  rpli = strstrstrip(RPL, RPL);
  baci = strstrstrip(BAC, BAC);
  opti = strstrstrip(OPT, OPT);
  scri = strstrstrip(SCR, SCR);
  srci = strstrstrip(SRC, SRC);
  noei = strstrstrip(NOE, NOE);
  vpgi = strstrstrip(VPG, VPG);
  md5i = strstrstrip(MD5, MD5);
  sh1i = strstrstrip(SH1, SH1);
  sh2i = strstrstrip(SH2, SH2);
  sh5i = strstrstrip(SH5, SH5);

}
return data;
}

char *pkg(){
char *pkg = strstrstrip(PKG, PKG);
  if(!pkg){
  return strdup("");
  } else {
  stripstr(pkg, PKG);
  }
return pkg;
}

char *ver(){
char *ver = strstrstrip(VER, VER);
  if(!ver){
  return strdup("");
  } else {
  stripstr(ver, VER);
  }
return ver;
}

char *rel(){
char *rel = strstrstrip(REL, REL);
  if(!rel){
  return strdup("");
  } else {
  stripstr(rel, REL);
  }
return rel;
}

char *eph(){
char *eph = strstrstrip(EPH, EPH);
  if(!eph){
  return strdup("");
  } else {
  stripstr(eph, EPH);
  }
return eph;
}

char *des(){
char *des = strstrstrip(DES, DES);
  if(!des){
  return strdup("");
  } else {
  stripstr(des, DES);
  }
return des;
}

char *ark(){
char *ark = strstrstrip(ARK, ARK);
  if(!ark){
  return strdup("");
  } else {
  stripstr(ark, ARK);
  }
return ark;
}

char *url(){
char *url = strstrstrip(URL, URL);
  if(!url){
  return strdup("");
  } else {
  stripstr(url, URL);
  }
return url;
}

char *lic(){
char *lic = strstrstrip(LIC, LIC);
  if(!lic){
  return strdup("");
  } else {
  stripstr(lic, LIC);
  }
return lic;
}

char *grp(){
char *grp = strstrstrip(GRP, GRP);
  if(!grp){
  return strdup("");
  } else {
  stripstr(grp, GRP);
  }
return grp;
}

char *dep(){
char *dep = strstrstrip(DEP, DEP);
  if(!dep){
  return strdup("");
  } else {
  stripstr(dep, DEP);
  }
return dep;
}

char *mep(){
char *mep = strstrstrip(MEP, MEP);
  if(!mep){
  return strdup("");
  } else {
  stripstr(mep, MEP);
  }
return mep;
}

char *cep(){
char *cep = strstrstrip(CEP, CEP);
  if(!cep){
  return strdup("");
  } else {
  stripstr(cep, CEP);
  }
return cep;
}

char *oep(){
char *oep = strstrstrip(OEP, OEP);
  if(!oep){
  return strdup("");
  } else {
  stripstr(oep, OEP);
  }
return oep;
}

char *cnf(){
char *cnf = strstrstrip(CNF, CNF);
  if(!cnf){
  return strdup("");
  } else {
  stripstr(cnf, CNF);
  }
return cnf;
}

char *rpl(){
char *rpl = strstrstrip(RPL, RPL);
  if(!rpl){
  return strdup("");
  } else {
  stripstr(rpl, RPL);
  }
return rpl;
}

char *bac(){
char *bac = strstrstrip(BAC, BAC);
  if(!bac){
  return strdup("");
  } else {
  stripstr(bac, BAC);
  }
return bac;
}

char *opt(){
char *opt = strstrstrip(OPT, OPT);
  if(!opt){
  return strdup("");
  } else {
  stripstr(opt, OPT);
  }
return opt;
}

char *scr(){
char *scr = strstrstrip(SCR, SCR);
  if(!scr){
  return strdup("");
  } else {
  stripstr(scr, SCR);
  }
return scr;
}

char *src(){
char *src = strstrstrip(SRC, SRC);
  if(!src){
  return strdup("");
  } else {
  stripstr(src, SRC);
  }
return src;
}

char *noe(){
char *noe = strstrstrip(NOE, NOE);
  if(!noe){
  return strdup("");
  } else {
  stripstr(noe, NOE);
  }
return noe;
}

char *vpg(){
char *vpg = strstrstrip(VPG, VPG);
  if(!vpg){
  return strdup("");
  } else {
  stripstr(vpg, VPG);
  }
return vpg;
}

char *md5(){
char *md5 = strstrstrip(MD5, MD5);
  if(!md5){
  return strdup("");
  } else {
  stripstr(md5, MD5);
  }
return md5;
}

char *sh1(){
char *sh1 = strstrstrip(SH1, SH1);
  if(!sh1){
  return strdup("");
  } else {
  stripstr(sh1, SH1);
  }
return sh1;
}

char *sh2(){
char *sh2 = strstrstrip(SH2, SH2);
  if(!sh2){
  return strdup("");
  } else {
  stripstr(sh2, SH2);
  }
return sh2;
}

char *sh5(){
char *sh5 = strstrstrip(SH5, SH5);
  if(!sh5){
  return strdup("");
  } else {
  stripstr(sh5, SH5);
  }
return sh5;
}

int main(void){
openfile();
char *a = strstrstrip("pkgname=", PKG);
char *b = strstrstrip("pkgver=", VER);
char *c = strstrstrip("url=", URL);
char *d = strstrstrip("source=", SRC);

printf("%s\n", a);
printf("%s\n", b);
printf("%s\n", c);
printf("%s\n", d);
/*
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
*/
return 0;
}
