#include <sys/stat.h>
#include "drconfig.h"
#include "drtrace.h"

config_file_t config_files[] = {
    {
        .name = "ui.cfg",
        .content =
        "ui = {\n"
        "    resolution = {\n"
        "        width = 800,\n"
        "        height = 600\n"
        "  }\n"
        "}\n"
    },
    {
        .name = "audio.cfg",
        .content =
        "audio = {\n"
        "    volume = 1,\n"
        "    pitch = 1\n"
        "}\n"
    },
};

static int parse_config(lua_State* L){
    
    double width,height,volume,pitch;
    lua_numberexpr( L, "ui.resolution.width", &width);
    lua_numberexpr( L, "ui.resolution.height", &height);
    lua_numberexpr( L, "audio.volume", &volume);
    lua_numberexpr( L, "audio.pitch", &pitch);
    
    R_INFO("width:%f", width);
    R_INFO("height:%f", height);
    R_INFO("volume:%f", volume);
    R_INFO("pitch:%f", pitch);

   return 0;    
}



int main(int argc, char** argv) {
    (void) argc;
    (void) argv;

    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    const size_t nb = sizeof (config_files) / sizeof (config_file_t);
    size_t i = 0;
    while (i < nb) {
        const char* fname = config_files[i].name;
        const char* fcontent = config_files[i].content;

        struct stat s;
        if (0 > stat(fname, &s)) {
            R_INFO("missing %s, creating default", fname);
            FILE* f = fopen(fname, "w");
            fprintf(f, "%s", fcontent);
            fclose(f);
        } else {
            R_INFO("using %s", fname);
        }

        if (luaL_dofile(L, fname) == 1) {
            R_ERR("Error loading %s", fname);
            return (1);
        } else {
            R_INFO("loading %s", fname);
        }
        ++i;
    }
    
    parse_config(L);

    lua_close(L);
    
    return (0);



}

