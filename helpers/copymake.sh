#!/usr/bin/bash
mkdir pbgep
mv 3dsgame/preferences pbgep/preferences

rm -r 3dsgame
cp -r ../3dsgame/3dsgame 3dsgame

rm -r 3dsgame/preferences
mv pbgep/preferences 3dsgame/
rm -r pbgep


make -j$(($(nproc) - 1))



#echo copying lib3dsgame

#cp ../3dsgame/lib/lib3dsgame.a lib3dsgame.a