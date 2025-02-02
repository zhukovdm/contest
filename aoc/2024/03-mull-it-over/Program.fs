(*
    https://adventofcode.com/2024/day/3

    Answer: 190604937
*)

open System
open System.IO
open System.Text.RegularExpressions

let readFile path =
    (new StreamReader(File.OpenRead(path))).ReadToEnd()

[<EntryPoint>]
let main argv =
    let input = readFile argv[0]
    let regex = Regex(@"mul\((\d{1,3}),(\d{1,3})\)")

    let result =
        regex.Matches(input)
        |> Seq.map (fun m -> (Int32.Parse m.Groups[1].Value) * (Int32.Parse m.Groups[2].Value))
        |> Seq.fold (+) 0

    printfn "%d" result
    0
