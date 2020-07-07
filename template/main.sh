#!/bin/bash

score_direction_file="score.cpp"    # 譜面を書いたcppファイル
score_file="written_score.py"       # 出力される譜面ファイル(ライブラリに依存)
writer_file="a.out"                 # ${score_file}をコンパイルするときの実行ファイル名(変更可能)
music_file="output.wav"              # 出力する音声ファイル(変更可能)
lib_dir="../lib"                    # ライブラリのディレクトリ名
success_flag=true

echo "==== compile score ====="
source ${lib_dir}/writer/compile.sh ${lib_dir}/writer
g++ -c -o S.o ${score_direction_file} -I ${lib_dir}/writer || success_flag=false
g++ -o ${writer_file}  S.o ${lib_dir}/writer/lib.o || success_flag=false
echo "compile statud:${success_flag}"

echo "==== generate score ====="
if $success_flag; then
    source ${lib_dir}/writer/compile.sh ${lib_dir}/writer || success_flag=false
    ./${writer_file} -o > ${score_file}
else
    echo "skip"
fi

echo "==== playing music ====="
if $success_flag; then
    python3 ${lib_dir}/player/main.py ${music_file} || success_flag=false
else
    echo "skip"
fi

if $success_flag; then
    echo "Successfully done!"
    exit 0
else
    echo "Fail...."
    exit 1
fi
