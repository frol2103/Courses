import http.cookiejar, urllib.request, string
from urllib.parse import urlencode


class Matta:
    login               = "";
    opener              = None;
    cj                  = None;
    #urls
    u_home              = "http://matta.info.ucl.ac.be"
    u_login             = "http://matta.info.ucl.ac.be/login/?next=/";

    def __init__(self):
        self.cj = http.cookiejar.CookieJar()
        self.opener = urllib.request.build_opener(urllib.request.HTTPCookieProcessor(self.cj))
    
    def login (self,login,password):
        self.opener.open(self.u_home)
        self.login  = login;
        data = {'username' : self.login, 'password' : password,
                'csrfmiddlewaretoken':self.getCookie("csrftoken").value,
                'next':"/"};  
        return self.pagePost(self.u_login,data)

    def pagePost(self, url, data=None):
        binary_data = urlencode(data).encode('utf8')
        return self.opener.open(url, binary_data);

    def page(self, url):
        return self.opener.open(url);

    def getPageSource(self, url):
        return self.opener.open(url).read()

    def getCookie(self,name):
        for cookie in self.cj:
            if cookie.name == name:
                return cookie;

