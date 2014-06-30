uses crt;
const input_file = 'odometer.in';
      output_file = 'odometer.out';
var fin, fout: text;
    x, y: int64;
    count: longint;
procedure generate;
var i, n_digit, same_digit, diff_digit, diff_pos: longint;
    v: int64;
begin
    for n_digit := 3 to 17 do
        for diff_digit := 0 to 9 do
            for diff_pos := 1 to n_digit do
                begin
                    if (diff_digit = 0) and (diff_pos = 1) then continue;
                    for same_digit := 0 to 9 do
                        if (same_digit <> diff_digit) then
                            begin
                                if (same_digit=0) and (diff_pos<>1) then continue;
                                v := 0;
                                for i := 1 to diff_pos-1 do v := v*10+same_digit;
                                v := v*10+diff_digit;
                                for i := diff_pos+1 to n_digit do v := v*10+same_digit;
                                if (v >= x) and (v <= y) then inc(count);
                            end;
                end;
end;
begin
    clrscr;
    assign(fin, input_file); reset(fin);
    assign(fout, output_file); rewrite(fout);
    readln(fin, x, y);
    count := 0;
    generate;
    write(fout, count);
    close(fin); close(fout);
end.
