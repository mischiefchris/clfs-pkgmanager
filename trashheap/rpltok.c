// replace one string at a time src, str, new
void rplstr(char *X, char *Y, char *Z){
     char *q;
     if ((q = strstr(X, Y)) == NULL){
         return;
     }
     int y_len = strlen(Y);
     int z_len = strlen(Z);
     int t_len = strlen(q+y_len);
     memmove(q+z_len,q+y_len,t_len+1);
     memcpy(q, Z, z_len);
}
