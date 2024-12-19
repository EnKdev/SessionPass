unit OtsvCode;

interface

uses
  SysUtils, Classes,
  System.Net.HttpClient, System.Net.URLClient,
  System.Net.Mime;

// typedecl
// Declare TOtsvCode as a class and define its functions.
type
  TOtsvCode = class
  public
    class function RequestOtsvCode(CodeFlag: Integer): string; static;
    class function CompareOtsvCode(const otsvCode: string; CodeFlag: Integer): Boolean; static;
  end;

implementation

uses
  HttpHelper;

{ TOtsvCode }

class function TOtsvCode.RequestOtsvCode(CodeFlag: Integer): string;
var
  Params: TStringList;
  Response: TBytes;
  Utf8Encoding: TUTF8Encoding;
begin
  Params := TStringList.Create;

  try
    Params.Add('cf=' + CodeFlag.ToString);
    Response := THttpHelper.HttpPost('https://enkdev.xyz/cdn/php/sessionpass/generateOtsvCode.php', Params);

    Utf8Encoding := TUTF8Encoding.Create;

    try
      Result := Utf8Encoding.GetString(Response);
    finally
      Utf8Encoding.Free;
    end;
  finally
    Params.Free;
  end;
end;

class function TOtsvCode.CompareOtsvCode(const otsvCode: string; CodeFlag: Integer): Boolean;
var
  Params: TStringList;
  Response: TBytes;
  Utf8Encoding: TUTF8Encoding;
  ResponseStr: string;
begin
  Params := TStringList.Create;
  Result := false;

  if (OtsvCode <> '') and (CodeFlag >= 0) then
  begin
    try
      Params.Add('code=' + OtsvCode);
      Params.Add('cf=' + CodeFlag.ToString);

      Response := THttpHelper.HttpPost('https://enkdev.xyz/cdn/php/sessionpass/compareCode.php', Params);

      Utf8Encoding := TUTF8Encoding.Create;

      try
        ResponseStr := Utf8Encoding.GetString(Response);

        if ResponseStr = 'true' then
          Result := True
        else
          Result := False;
      finally
        Utf8Encoding.Free;
      end;
    finally
      Params.Free;
    end;
  end
  else
    Writeln('otsvCode is null, can''t check.');

end;

end.
