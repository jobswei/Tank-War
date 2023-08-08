
extern int map[26][26];
void set_prop_map(int x, int y, int val){
    map[y][x]=val;
    map[y+1][x]=val;
    map[y][x+1]=val;
    map[y+1][x+1]=val;
}

