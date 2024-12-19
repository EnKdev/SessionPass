program EnKdev.SessionPass.Delphi.Tests;

{$APPTYPE CONSOLE}

{$R *.res}

uses
  System.SysUtils,
  OtsvCode;

var
  OtsvCode: string;
  Oc: TOtsvCode;
  IsSame: Boolean;

function Eval(IsSame: Boolean): Boolean;
begin
  if isSame then
    Writeln('Code check success')
  else
    Writeln('Code check failed');
end;
  
begin
  try
    Oc := TOtsvCode.Create;

    Writeln('TEST1 - Code Check (small) [codeFlag=0]');
    OtsvCode := Oc.RequestOtsvCode(0);
    Writeln('Received code (' + OtsvCode + '), checking for integrity...');
    IsSame := Oc.CompareOtsvCode(OtsvCode, 0);

    Eval(IsSame);
    
    Writeln('------------------');

    Writeln('TEST2 - Code Check (medium) [codeFlag=1]');
    OtsvCode := Oc.RequestOtsvCode(1);
    Writeln('Received code (' + OtsvCode + '), checking for integrity...');
    IsSame := Oc.CompareOtsvCode(OtsvCode, 1);

    Eval(IsSame);

    Writeln('------------------');

    Writeln('TEST3 - Code Check (medium) [codeFlag=2]');
    OtsvCode := Oc.RequestOtsvCode(2);
    Writeln('Received code (' + OtsvCode + '), checking for integrity...');
    IsSame := Oc.CompareOtsvCode(OtsvCode, 2);

    Eval(IsSame);

    Writeln('------------------');

    Writeln('TEST4 - Code Faking');
    Writeln('Setting OtsvCode to abskd...');
    OtsvCode := 'abskd';
    Writeln('Received code (' + OtsvCode + '), checking for integrity...');
    IsSame := Oc.CompareOtsvCode(OtsvCode, 2);
    Eval(IsSame);
    
    Writeln('------------------');

    Writeln('TEST5 - Null/Empty String');
    Writeln('Emptying OtsvCode...');
    OtsvCode := '';
    Writeln('Received code (' + OtsvCode + '), checking for integrity...');
    IsSame := Oc.CompareOtsvCode(OtsvCode, 2);

    Writeln('Test concluded.');
  finally
    Oc.Free;
  end;
end.
