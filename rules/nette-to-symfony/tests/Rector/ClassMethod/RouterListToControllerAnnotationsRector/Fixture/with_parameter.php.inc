<?php

namespace Rector\NetteToSymfony\Tests\Rector\MethodCall\RouterListToControllerAnnotationsRetor\Fixture;

use Nette\Application\IPresenter;
use Nette\Application\IResponse;
use Nette\Application\Routers\Route;
use Nette\Application\Routers\RouteList;

final class WithParameterRouterFactory
{
    public function create(): RouteList
    {
        $routeList = new RouteList();

        $routeList[] = new Route('some-path/<id>', WithParameterSomePresenter::class);

        return $routeList;
    }
}

final class WithParameterSomePresenter implements IPresenter
{
    /**
     * @doto
     */
    public function run(\Nette\Application\Request $request): IResponse
    {
    }
}

?>
-----
<?php

namespace Rector\NetteToSymfony\Tests\Rector\MethodCall\RouterListToControllerAnnotationsRetor\Fixture;

use Symfony\Component\Routing\Annotation\Route;
use Nette\Application\IPresenter;
use Nette\Application\IResponse;
use Nette\Application\Routers\RouteList;

final class WithParameterRouterFactory
{
    public function create(): RouteList
    {
        $routeList = new RouteList();

        return $routeList;
    }
}

final class WithParameterSomePresenter implements IPresenter
{
    /**
     * @doto
     * @Route(path="some-path/{id}")
     */
    public function run(\Nette\Application\Request $request): IResponse
    {
    }
}

?>
