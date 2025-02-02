(*
    https://adventofcode.com/2024/day/1

    Answer: 1651298
*)

open System.IO

type TwoArrays<'T> = { ls: 'T[]; rs: 'T[] }

let parse = System.Int32.Parse

let readLines path =
    seq {
        use reader = new StreamReader(File.OpenRead(path))

        while not reader.EndOfStream do
            reader.ReadLine()
    }

[<EntryPoint>]
let main argv =
    let data = readLines argv[0]

    let tuples =
        data
        |> Seq.toArray
        |> Array.choose (fun line ->
            match line.Split(' ', System.StringSplitOptions.RemoveEmptyEntries) with
            | [| l; r |] -> Some(parse l, parse r)
            | _ -> None)
        |> Array.fold
            (fun acc (l, r) ->
                { ls = Array.append acc.ls [| l |]
                  rs = Array.append acc.rs [| r |] })
            { ls = [||]; rs = [||] }

    let result =
        Array.zip (Array.sort tuples.ls) (Array.sort tuples.rs)
        |> Array.map (fun (l, r) -> abs (l - r))
        |> Array.fold (+) 0

    printfn "%d" result
    0
