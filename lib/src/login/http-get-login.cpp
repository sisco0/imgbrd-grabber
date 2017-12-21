#include "login/http-get-login.h"
#include <QUrlQuery>
#include "models/site.h"


HttpGetLogin::HttpGetLogin(Site *site, QNetworkAccessManager *manager, MixedSettings *settings)
	: HttpLogin("get", site, manager, settings)
{}

QNetworkReply *HttpGetLogin::getReply(const QString &loginUrl, const QUrlQuery &query) const
{
	QUrl url = m_site->fixUrl(loginUrl);
	url.setQuery(query);
	QNetworkRequest request(url);

	return m_manager->get(request);
}
