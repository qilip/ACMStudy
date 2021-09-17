defmodule Test do
    def print(n) do
        unless n == "42\n" or n == :eof do
            IO.write(n)
            print(IO.gets(""))
        end
    end
end

Test.print(IO.gets(""))
