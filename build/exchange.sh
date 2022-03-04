NAME="plug"
gcc $NAME.def $NAME.a -shared -lwinmm -lWs2_32 -o $NAME.dll -Wl,--out-implib,$NAME.dll.a
echo "please use msvc tool run"
echo "path:"
echo `pwd`
echo "lib /def:$NAME.def  /name:$NAME.dll  /out:$NAME.lib /MACHINE:X86"