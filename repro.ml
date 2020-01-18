


let () = Lib.attachConsole()

let () = Lib.nativePrint("test after alloc...")

let () = print_endline ("Print from ocaml after alloc...")

let () = Lib.nativePrint("finished!")
