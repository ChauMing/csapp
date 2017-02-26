/**
 * dup2(STDOUT_FILENO, STDIN_FILENO);
 * 将上一个进程的stdout 拷贝文件表项到stdin, 
 * 因为 stdout 和 stdin 在 fock出来的进程里是共享的
 * 
 */