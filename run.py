import os

def run():
    os.system("rmdir /S /Q build_com")
    os.system("cmake -B build_com comm")
    os.system("cmake --build build_com")

    os.system("del app\\inc\\comm.h")
    os.system("copy comm\\inc\\comm.h app\\inc\\")
    os.system("del app\\lib\\comm.lib")
    os.system("del app\\lib\\comm.pdb")
    os.system("copy build_com\\Debug\\* app\\lib\\")

    os.system("rmdir /S /Q build")
    os.system("cmake -B build app")
    os.system("cmake --build build")
    os.system(".\\build\\Debug\\app.exe")

if __name__ == '__main__':
    run()