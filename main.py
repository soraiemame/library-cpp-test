def define_env(env):
    @env.macro
    def print_file(file_path):
        res = ""
        with open(file_path) as lines:
            for line in lines:
                res += line
        return f'```c++\n{res}\n```\n'
