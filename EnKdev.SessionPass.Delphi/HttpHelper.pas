unit HttpHelper;

interface

uses
  System.Net.HttpClient, System.Net.HttpClientComponent, System.Net.URLClient,
  System.Net.Mime, Classes, SysUtils;

// typedecl.
// Declare THttpHelper as a class and define a function of it.
type
  THttpHelper = class
  public
    class function HttpPost(const AUri: string; const APairs: TStrings): TBytes; static;
  end;


implementation

class function THttpHelper.HttpPost(const AUri: string; const APairs: TStrings): TBytes;
var
  HttpClient: TNetHTTPClient;
  Content: TMultipartFormData;
  Response: IHTTPResponse;
  I: Integer;
begin
  HttpClient := TNetHTTPClient.Create(nil);
  Content := TMultipartFormData.Create;

  try
    // Add each Key-Value-Pair to the form data.
    for I := 0 to APairs.Count - 1 do
      Content.AddField(APairs.Names[I], APairs.ValueFromIndex[I]);

    // Perform the HTTP Post request
    Response := HttpClient.Post(AUri, Content);

    // Convert the response
    Result := TEncoding.UTF8.GetBytes(Response.ContentAsString);
  finally
    Content.Free;
    HttpClient.Free;
  end;
end;

end.
