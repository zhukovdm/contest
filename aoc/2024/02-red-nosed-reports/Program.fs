(*
    https://adventofcode.com/2024/day/2

    Answer: 
*)

open System
open System.IO

let readLines path =
    seq {
        use reader = new StreamReader(File.OpenRead(path))

        while not reader.EndOfStream do
            reader.ReadLine()
    }

let allIncreasing (xs: seq<(int * int)>) =
    xs
    |> Seq.map (fun (l, r) -> l > r && l - r >= 1 && l - r <= 3)
    |> Seq.fold (&&) true

let allDecreasing (xs: seq<(int * int)>) =
    xs |> Seq.map (fun (l, r) -> (r, l)) |> allIncreasing

[<EntryPoint>]
let main argv =
    let data = readLines argv[0]

    let result =
        data
        |> Seq.map (fun line -> Array.toSeq (line.Split(' ', StringSplitOptions.RemoveEmptyEntries)))
        |> Seq.map (fun line -> Seq.map Int32.Parse line)
        |> Seq.map (fun line -> Seq.zip line (Seq.skip 1 line))
        |> Seq.map (fun line -> allIncreasing line || allDecreasing line)
        |> Seq.fold (fun acc all -> if all then acc + 1 else acc) 0

    printfn "%d" result
    0
