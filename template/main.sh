#!/bin/bash

score_direction_file="score.cpp"    # 譜面を書いたcppファイル
score_file="written_score.py"       # 出力される譜面ファイル(ライブラリに依存)
writer_file="a.out"                 # ${score_file}をコンパイルするときの実行ファイル名(変更可能)
music_file="music.mp3"              # 出力する音声ファイル(変更可能)
lib_dir="../lib"                    # ライブラリのディレクトリ名

echo "==== compile score ====="
source ${lib_dir}/writer/compile.sh ${lib_dir}/writer
g++ -c -o S.o ${score_direction_file} -I ${lib_dir}/writer
g++ -o ${writer_file}  S.o ${lib_dir}/writer/lib.o

echo "==== generate score ====="
source ${lib_dir}/writer/compile.sh ${lib_dir}/writer
./${writer_file} -o > ${score_file}

echo "==== playing music ====="
python3 ${lib_dir}/player/main.py ${music_file}

