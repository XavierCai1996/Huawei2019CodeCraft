# 查找当前目录下的所有源文件
aux_source_directory(. DIR_SCENARIO_SRCS)

# 指定生成目标
add_library(scenario SHARED ${DIR_SCENARIO_SRCS})
