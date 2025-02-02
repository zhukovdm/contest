(*
    https://adventofcode.com/2024/day/2

    Answer, Part 1: 486
    Answer, Part 2: 540
*)

open System
open System.IO

let readLines path =
    seq {
        use reader = new StreamReader(File.OpenRead(path))

        while not reader.EndOfStream do
            reader.ReadLine()
    }

let selfZip (xs: seq<int>) = Seq.zip xs (Seq.skip 1 xs)

let withRemovedItem (xs: seq<int>) =
    seq { 0 .. (Seq.length xs) - 1 }
    |> Seq.map (fun ir ->
        Seq.mapi (fun ix x -> if ix = ir then None else Some x) xs
        |> Seq.choose (fun x -> x))
    |> Seq.map selfZip

let expandLine (xs: seq<int>) =
    Seq.concat [ (xs |> selfZip |> Seq.singleton); (withRemovedItem xs) ]

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
        |> Seq.map (fun line -> expandLine line)
        |> Seq.map (fun arrs ->
            arrs
            |> Seq.fold (fun acc xs -> acc || allIncreasing xs || allDecreasing xs) false)
        |> Seq.fold (fun acc all -> if all then acc + 1 else acc) 0

    printfn "%d" result
    0
